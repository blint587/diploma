class _Version:
    def __init__(self):
        self.version = '0.2.17.0'

    def __repr__(self):
        return f"version: {self.version}"


Version = _Version()
