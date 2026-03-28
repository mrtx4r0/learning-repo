class Task:
	""" class Task """
	def __init__(self, title, done=False, created_at=None):
		self.title = title
		self.done = done
		self.created_at = created_at or datetime.now().isoformat()

	def to_dict(self):
		return {
			"title": self.title,
			"done": self.done,
			"created_at": self.created_at,
		}

	@classmethod
	def from_dict(cls, data):
		return cls(
			title=data["title"],
            done=data["done"],
            created_at=data["created_at"],
        )
