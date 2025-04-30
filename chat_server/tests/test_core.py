import pytest
from source.core import is_valid_nickname, format_message

def test_valid_nickname():
    assert is_valid_nickname("Prasanth")
    assert is_valid_nickname("Daphne")
    assert not is_valid_nickname("a!")        # special char
    assert not is_valid_nickname("ab")        # too short
    assert not is_valid_nickname("thisisaverylongname")  # too long

def test_message_formatting():
    assert format_message("Prasanth", "Hello") == "Prasanth: Hello"
    assert format_message("Bob", "Hey!") == "Bob: Hey!"