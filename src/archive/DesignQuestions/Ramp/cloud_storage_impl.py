from cloud_storage import CloudStorage
from collections import defaultdict
import heapq


class CloudStorageImpl(CloudStorage):
    def __init__(self):
        # TODO: implement
        self.files = defaultdict(int)
        self.users = defaultdict(int)
        self.users_files = defaultdict(set)
        self.file_to_user = defaultdict(str)
        # map user_id to 2 things: dict of user_files and capacity
        self.user_backup = defaultdict(list)
        self.original_capacity = {}

    # TODO: implement interface methods here
    def add_file(self, name: str, size: int) -> bool:
        if name not in self.files:
            self.files[name] = size
            self.file_to_user[name] = "admin"
            return True
        return False

    def get_file_size(self, name: str) -> int | None:
        if name in self.files:
            return self.files[name]
        return None

    def delete_file(self, name: str) -> int | None:
        if name in self.files:
            val = self.files[name]
            owner_id = self.file_to_user[name]
            # need to pop from the owner, and add to capacity
            if owner_id != "admin":
                self.users_files[owner_id].remove(name)
                self.users[owner_id] += val
            self.files.pop(name)
            self.file_to_user.pop(name)
            return val
        return None

    def get_n_largest(self, prefix: str, n: int) -> list[str]:
        # make tuple of (size, name) and for all files with the prefix,
        # we push them into a minheap
        result = []
        valid_strings = []
        maxHeap = []
        for name in self.files:
            if name.startswith(prefix):
                valid_strings.append(name)
        # so now, we have array full of strings that are valid, throw into min heap of tuples
        for string in valid_strings:
            heapq.heappush(maxHeap, (-1 * self.files[string], string))

        # now we have mazHeap, push the top n
        for _ in range(n):
            if len(maxHeap) > 0:
                size, name = heapq.heappop(maxHeap)
                val = name + "(" + str(-1 * size) + ")"
                result.append(val)

        return result

    def add_user(self, user_id: str, capacity: int) -> bool:
        if user_id not in self.users:
            self.users[user_id] = capacity
            self.original_capacity[user_id] = capacity
            return True
        return False

    def add_file_by(self, user_id: str, name: str, size: int) -> int | None:
        # if the file is too big for the available capacity
        if (
            user_id not in self.users
            or self.users[user_id] < size
            or name in self.files
        ):
            return None

        self.users[user_id] -= size
        self.users_files[user_id].add(name)
        self.file_to_user[name] = user_id
        self.files[name] = size
        return self.users[user_id]

    def merge_user(self, user_id_1: str, user_id_2: str) -> int | None:
        if (
            user_id_1 not in self.users
            or user_id_2 not in self.users
            or user_id_1 == user_id_2
        ):
            return None

        cpy_files = self.users_files[user_id_2]
        cpy_capacity = self.users[user_id_2]

        # move them into account 1
        self.users[user_id_1] += cpy_capacity
        self.users_files[user_id_1].update(cpy_files)
        for file_name in cpy_files:
            self.file_to_user[file_name] = user_id_1

        # remove the account 2
        self.users.pop(user_id_2)
        self.users_files.pop(user_id_2)

        return self.users[user_id_1]

    def backup_user(self, user_id: str) -> int | None:
        if user_id not in self.users:
            return None

        files = []
        for file in self.users_files[user_id]:
            files.append((file, self.files[file]))
        self.user_backup[user_id] = files
        return len(files)

    def restore_user(self, user_id: str) -> int | None:
        num_restored = 0
        if user_id not in self.users:
            return None

        # if no backups, delete everything
        # first delete everything from file_to_user
        if user_id not in self.user_backup:
            for file_name in self.users_files[user_id]:
                self.delete_file(file_name)
        else:
            # reset capacity
            self.users[user_id] = self.original_capacity[user_id]
            for file, size in self.backup_user[user_id]:
                self.users_files[user_id].add(file)

            for file, size in self.users_files:
                if self.add_file_by(user_id, file, size):
                    num_restored += 1

        return num_restored
