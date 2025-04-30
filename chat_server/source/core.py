def is_valid_nickname(nick):
    """Nicknames should be alphanumeric and 3–12 chars."""
    return nick.isalnum() and 3 <= len(nick) <= 12

def format_message(nickname, message):
    return f"{nickname}: {message}"