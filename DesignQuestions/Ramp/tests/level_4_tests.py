import inspect, os, sys

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from timeout_decorator import timeout
import unittest
from cloud_storage_impl import CloudStorageImpl


class Level4Tests(unittest.TestCase):
    """
    The test suit below includes 10 tests for Level 4.

    All have the same score.
    You are not allowed to modify this file,
    but feel free to read the source code
    to better understand what is happening in every specific case.
    """

    failureException = Exception

    @classmethod
    def setUp(cls):
        cls.storage = CloudStorageImpl()

    @timeout(0.4)
    def test_level_4_case_01_pure_backup(self):
        self.assertTrue(self.storage.add_user("user", 20))
        self.assertEqual(self.storage.add_file_by("user", "/file", 15), 5)
        self.assertEqual(self.storage.backup_user("user"), 1)
        self.assertEqual(self.storage.get_file_size("/file"), 15)

    @timeout(0.4)
    def test_level_4_case_02_restore(self):
        self.assertTrue(self.storage.add_user("user", 20))
        self.assertEqual(self.storage.add_file_by("user", "/file", 15), 5)
        self.assertEqual(self.storage.backup_user("user"), 1)
        self.assertEqual(self.storage.delete_file("/file"), 15)
        self.assertEqual(self.storage.restore_user("user"), 1)
        self.assertEqual(self.storage.get_file_size("/file"), 15)

    @timeout(0.4)
    def test_level_4_case_03_restore_deletes_other_files(self):
        self.assertTrue(self.storage.add_user("user", 40))
        self.assertEqual(self.storage.backup_user("user"), 0)
        self.assertEqual(self.storage.add_file_by("user", "/dir/file.txt", 30), 10)
        self.assertEqual(self.storage.add_file_by("user", "/dir/file.mp4", 10), 0)
        self.assertEqual(self.storage.restore_user("user"), 0)
        self.assertIsNone(self.storage.get_file_size("/dir/file.txt"))

    @timeout(0.4)
    def test_level_4_case_04_multiple_users(self):
        self.assertTrue(self.storage.add_user("user1", 40))
        self.assertTrue(self.storage.add_user("user2", 40))
        self.assertEqual(self.storage.add_file_by("user1", "/dir/text.txt", 20), 20)
        self.assertEqual(self.storage.add_file_by("user2", "/movie.mp4", 10), 30)
        self.assertEqual(self.storage.backup_user("user1"), 1)
        self.assertEqual(self.storage.delete_file("/dir/text.txt"), 20)
        self.assertEqual(self.storage.add_file_by("user1", "/file", 10), 30)
        self.assertEqual(self.storage.restore_user("user1"), 1)
        expected = ["/dir/text.txt(20)", "/movie.mp4(10)"]
        self.assertEqual(self.storage.get_n_largest("/", 4), expected)
        self.assertEqual(self.storage.merge_user("user2", "user1"), 50)
        self.assertEqual(self.storage.backup_user("user2"), 2)
        self.assertEqual(self.storage.delete_file("/dir/text.txt"), 20)
        self.assertEqual(self.storage.restore_user("user2"), 2)
        self.assertEqual(self.storage.get_n_largest("/", 4), expected)

    @timeout(0.4)
    def test_level_4_case_05_multiple_backups(self):
        self.assertTrue(self.storage.add_user("user", 100))
        self.assertEqual(self.storage.add_file_by("user", "/file1", 30), 70)
        self.assertEqual(self.storage.backup_user("user"), 1)
        self.assertEqual(self.storage.add_file_by("user", "/file3", 10), 60)
        self.assertEqual(self.storage.backup_user("user"), 2)
        self.assertEqual(self.storage.add_file_by("user", "/file4", 20), 40)
        self.assertEqual(self.storage.restore_user("user"), 2)
        expected = ["/file1(30)", "/file3(10)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)

    @timeout(0.4)
    def test_level_4_case_06_unexisting_users(self):
        self.assertTrue(self.storage.add_user("someUser", 100))
        self.assertIsNone(self.storage.restore_user("user"))
        self.assertIsNone(self.storage.backup_user("user"))
        self.assertIsNone(self.storage.add_file_by("user", "/file", 10))
        self.assertIsNone(self.storage.get_file_size("/file"))
        self.assertIsNone(self.storage.backup_user("user"))
        self.assertTrue(self.storage.add_user("user", 10))
        self.assertEqual(self.storage.restore_user("user"), 0)
        self.assertIsNone(self.storage.get_file_size("/file"))

    @timeout(0.4)
    def test_level_4_case_07_mixed_1(self):
        self.assertTrue(self.storage.add_user("user1", 40))
        self.assertTrue(self.storage.add_user("user2", 40))
        self.assertEqual(self.storage.add_file_by("user1", "/dir/text.txt", 20), 20)
        self.assertEqual(self.storage.add_file_by("user2", "/movie.mp4", 10), 30)
        self.assertTrue(self.storage.add_file("/directory/file", 30))
        self.assertEqual(self.storage.backup_user("admin"), 1)
        self.assertEqual(self.storage.delete_file("/directory/file"), 30)
        self.assertEqual(self.storage.backup_user("user1"), 1)
        self.assertEqual(self.storage.backup_user("user2"), 1)
        self.assertEqual(self.storage.merge_user("user2", "user1"), 50)
        self.assertIsNone(self.storage.restore_user("user1"))
        self.assertEqual(self.storage.restore_user("user2"), 1)
        self.assertEqual(self.storage.restore_user("admin"), 1)
        self.assertIsNone(self.storage.get_file_size("/dir/text.txt"))
        self.assertEqual(self.storage.get_file_size("/movie.mp4"), 10)
        self.assertEqual(self.storage.get_file_size("/directory/file"), 30)

    @timeout(0.4)
    def test_level_4_case_08_mixed_2(self):
        self.assertTrue(self.storage.add_user("user", 10))
        self.assertEqual(self.storage.add_file_by("user", "/files/file", 5), 5)
        self.assertEqual(self.storage.add_file_by("user", "/file.txt", 4), 1)
        self.assertEqual(self.storage.backup_user("user"), 2)
        self.assertEqual(self.storage.delete_file("/file.txt"), 4)
        self.assertTrue(self.storage.add_file("/file.txt", 10))
        self.assertEqual(self.storage.restore_user("user"), 1)
        self.assertEqual(self.storage.get_file_size("/file.txt"), 10)
        self.assertEqual(self.storage.delete_file("/file.txt"), 10)
        self.assertEqual(self.storage.restore_user("user"), 2)
        self.assertEqual(self.storage.get_file_size("/file.txt"), 4)

    @timeout(0.4)
    def test_level_4_case_09_mixed_3(self):
        self.assertTrue(self.storage.add_user("user1", 10))
        self.assertTrue(self.storage.add_user("user2", 6))
        self.assertEqual(self.storage.add_file_by("user1", "/dir/file1.mp4", 7), 3)
        self.assertEqual(self.storage.add_file_by("user1", "/file3.mp4", 3), 0)
        self.assertEqual(self.storage.backup_user("user1"), 2)
        self.assertEqual(self.storage.backup_user("user2"), 0)
        self.assertEqual(self.storage.delete_file("/dir/file1.mp4"), 7)
        self.assertEqual(self.storage.delete_file("/file3.mp4"), 3)
        self.assertEqual(self.storage.add_file_by("user2", "/dir/file1.mp4", 1), 5)
        self.assertEqual(self.storage.restore_user("user1"), 1)
        self.assertEqual(self.storage.get_file_size("/dir/file1.mp4"), 1)
        self.assertEqual(self.storage.restore_user("user2"), 0)
        self.assertEqual(self.storage.add_file_by("user2", "/dir/file2.mov", 4), 2)
        self.assertEqual(self.storage.merge_user("user1", "user2"), 9)
        self.assertFalse(self.storage.add_user("user1", 20))
        self.assertTrue(self.storage.add_user("user2", 4))
        self.assertEqual(self.storage.backup_user("admin"), 0)
        self.assertIsNone(self.storage.add_file_by("user2", "/dir/file3.png", 5))
        self.assertEqual(self.storage.merge_user("user1", "user2"), 13)
        expected = ["/dir/file2.mov(4)", "/file3.mp4(3)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)
        self.assertEqual(self.storage.restore_user("user1"), 2)
        self.assertTrue(self.storage.add_file("/new_file", 1))
        expected = ["/dir/file1.mp4(7)", "/file3.mp4(3)", "/new_file(1)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertEqual(self.storage.restore_user("admin"), 0)
        expected = ["/dir/file1.mp4(7)", "/file3.mp4(3)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertIsNone(self.storage.restore_user("user2"))

    @timeout(0.4)
    def test_level_4_case_10_mixed_4(self):
        self.assertTrue(self.storage.add_user("user", 10))
        self.assertTrue(self.storage.add_user("newUser", 10))
        self.assertEqual(self.storage.add_file_by("user", "/pic/img.png", 5), 5)
        self.assertEqual(self.storage.add_file_by("newUser", "/report.xml", 4), 6)
        self.assertEqual(self.storage.backup_user("user"), 1)
        self.assertEqual(self.storage.delete_file("/report.xml"), 4)
        self.assertEqual(self.storage.delete_file("/pic/img.png"), 5)
        self.assertEqual(self.storage.add_file_by("user", "/pic/img.png", 4), 6)
        self.assertEqual(self.storage.restore_user("user"), 1)
        self.assertIsNone(self.storage.get_file_size("/file.txt"))
        self.assertEqual(self.storage.get_file_size("/pic/img.png"), 5)
        self.assertEqual(self.storage.delete_file("/pic/img.png"), 5)
        self.assertEqual(self.storage.add_file_by("user", "/pic/img.png", 9), 1)
        self.assertEqual(self.storage.get_file_size("/pic/img.png"), 9)
        self.assertEqual(self.storage.merge_user("user", "newUser"), 11)
        self.assertTrue(self.storage.add_user("newUser", 60))
        self.assertEqual(self.storage.merge_user("user", "newUser"), 71)
        self.assertEqual(self.storage.restore_user("user"), 1)
        self.assertEqual(self.storage.get_file_size("/pic/img.png"), 5)
        self.assertEqual(self.storage.add_file_by("user", "/img.png", 2), 73)
        self.assertEqual(self.storage.backup_user("user"), 2)
        self.assertIsNone(self.storage.backup_user("newUser"))
        self.assertEqual(self.storage.delete_file("/pic/img.png"), 5)
        self.assertIsNone(self.storage.add_file_by("user", "/img.png", 9))
        self.assertIsNone(self.storage.add_file_by("user", "/img.png", 8))
        expected = ["/img.png(2)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)
