import time
import requests
import docker

# List of service health endpoints
SERVICES = {
    "app1": "http://localhost:5001/health",
    "app2": "http://localhost:5002/health",
}
log_file = "./logs/health_monitor.log"
CHECK_INTERVAL = 10  # seconds

# Connect to local Docker daemon
client = docker.from_env()

def is_service_healthy(url):
    try:
        response = requests.get(url, timeout=3)
        return response.status_code == 200
    except requests.exceptions.RequestException:
        return False

def restart_service(service_name):
    print(f"[ALERT] Restarting {service_name}...")
    try:
        container = client.containers.get(service_name)
        container.restart()
        with open(log_file, "a") as log:
            log.write(f"{time.ctime()}:[INFO] {service_name} restarted.\n")
        print(f"[INFO] {service_name} restarted successfully.")
    except docker.errors.NotFound:
        print(f"[ERROR] {service_name} container not found!")
    except Exception as e:
        print(f"[ERROR] Failed to restart {service_name}: {e}")

def monitor_services():
    while True:
        for service_name, url in SERVICES.items():
            if not is_service_healthy(url):
                print(f"[WARNING] {service_name} is DOWN!")
                with open(log_file, "a") as log:
                    log.write(f"{time.ctime()}:[WARNING] {service_name} is DOWN!\n")
                restart_service(service_name)
            else:
                print(f"[OK] {service_name} is healthy.")
                with open(log_file, "a") as log:
                    log.write(f"{time.ctime()}:[OK] {service_name} is healthy.\n")
        time.sleep(CHECK_INTERVAL)

if __name__ == "__main__":
    monitor_services()