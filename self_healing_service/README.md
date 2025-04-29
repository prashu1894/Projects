
Docker: Docker is a platform that makes it easy to build, ship, and run applications inside lightweight, portable containers.
Container: A container is like a mini-computer inside your real computer.It has its own files, libraries, and settings.
It isolates your app from the host system — so whatever works in your container will work the same everywhere (your laptop, a server, AWS, GCP...).
It’s much lighter than a full virtual machine (VM)


Design Idea:
Isolation: Each app runs separately — no conflicts.
Portability: Containers can move from laptop → cloud → datacenter easily.
Efficiency: Containers share the same OS kernel — super lightweight compared to full VMs.
Resilience: Easy to restart, scale up/down, and recover containers without affecting the whole system.


📋 Docker Architecture Flow
1. Host Machine
    → This is your physical computer or virtual server.
    → It runs an operating system (Linux, Windows, MacOS, etc.).
2. Docker Engine
    → A lightweight runtime that installs on the host machine.
    → Docker Engine is responsible for:
        Managing images
        Running containers
        Networking containers
        Communicating with Docker CLI or APIs

3. Containers
→ On top of the Docker Engine, you have containers.
→ Each container is:
    Isolated from the host system
    Has its own filesystem, libraries, environment
    Runs a specific application or service (like a Flask app, database, etc.)

4. Interaction
    Users or scripts send commands (e.g., docker run, docker ps) to the Docker Engine.
    Docker Engine spins up containers based on predefined images.
    Containers run apps in a self-contained environment.

5. Scaling and Restarting
    If one container crashes, Docker (or tools like Kubernetes) can restart it automatically.
    You can scale by running multiple containers from the same image.