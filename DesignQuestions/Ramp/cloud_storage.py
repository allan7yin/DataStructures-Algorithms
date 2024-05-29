from abc import ABC


class CloudStorage(ABC):
    """
    `CloudStorage` interface.
    """

    def add_file(self, name: str, size: int) -> bool:
        """
        Should add a new file `name` to the storage.
        `size` is the amount of memory required in bytes.
        The current operation fails if a file with the same `name`
        already exists.
        Returns `True` if the file was added successfully or `False`
        otherwise.
        """
        # default implementation
        return False

    def get_file_size(self, name: str) -> int | None:
        """
        Should return the size of the file `name` if it exists, or
        `None` otherwise.
        """
        # default implementation
        return None

    def delete_file(self, name: str) -> int | None:
        """
        Should delete the file `name`.
        Returns the deleted file size if the deletion was successful
        or `None` if the file does not exist.
        """
        # default implementation
        return None

    def get_n_largest(self, prefix: str, n: int) -> list[str]:
        """
        Should return the list of strings representing the names of
        the top `n` largest files with names starting with `prefix`
        in the following format:
        `["<name_1>(<size_1>)", ..., "<name_n>(<size_n>)"]`.
        Returned files should be sorted by size in descending order,
        or in case of a tie, sorted in
        [lexicographical](keyword://lexicographical-order-for-
        strings) order of the names.
        If there are no such files, return an empty list.
        If the number of such files is less than `n`, all of them
        should be returned in the specified format.
        """
        # default implementation
        return []

    def add_user(self, user_id: str, capacity: int) -> bool:
        """
        Should add a new user in the system, with `capacity` as
        their storage limit in bytes.
        The total size of all files owned by `user_id` cannot exceed
        `capacity`.
        The operation fails if a user with `user_id` already exists.
        Returns `True` if a user with `user_id` is successfully
        created, or `False` otherwise.
        """
        # default implementation
        return False

    def add_file_by(self, user_id: str, name: str, size: int) -> int | None:
        """
        Should behave in the same way as the `add_file` from Level
        1, but the added file should be owned by the user with
        `user_id`.
        A new file cannot be added to the storage if doing so will
        exceed the user's `capacity` limit.
        Returns the remaining capacity of the user if the file is
        added successfully, or `None` otherwise.

        *Note that* all queries calling the `add_file` operation
        implemented during Level 1 are run by the user with
        `user_id = "admin"`, who has unlimited storage capacity.
        """
        # default implementation
        return None

    def merge_user(self, user_id_1: str, user_id_2: str) -> int | None:
        """
        Should merge the account of `user_id_2` with the
        `user_id_1`.
        Ownership of all of `user_id_2`'s files is transferred to
        `user_id_1`, and any remaining storage capacity is also
        added to `user_id_1`'s limit.
        `user_id_2` is deleted if the merge is successful.
        Returns the remaining capacity of `user_id_1` after merging,
        or `None` if one of the users does not exist or `user_id_1`
        is equal to `user_id_2`.
        It is guaranteed that neither `user_id_1` nor `user_id_2`
        equals `"admin"`.
        """
        # default implementation
        return None

    def backup_user(self, user_id: str) -> int | None:
        """
        Should back up the current state of all files owned by
        `user_id` - i.e., file names and sizes.
        The backup is stored on a separate storage system and is not
        affected by any new file manipulation queries.
        Overwrites any backups for the same user if previous backups
        exist.
        Returns the number of backed-up files, or `None` if
        `user_id` does not exist.
        """
        # default implementation
        return None

    def restore_user(self, user_id: str) -> int | None:
        """
        Should restore the state of `user_id`'s files to the latest
        backup.
        If there was no backup, all of `user_id`'s files are
        deleted.
        If a file can't be restored because another user added
        another file with the same name, it is ignored.
        Returns the number of the files that are successfully
        restored or `None` if `user_id` does not exist.

        *Note that* `merge_user` does not affect `user_id_1`'s
        backup, and `user_id_2` is deleted along with its backup.
        *Note that* the `restore_user` operation does not affect the
        user's capacity.
        """
        # default implementation
        return None
