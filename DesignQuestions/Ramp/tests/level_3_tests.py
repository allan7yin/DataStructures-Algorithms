import inspect, os, sys

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from timeout_decorator import timeout
import unittest
from cloud_storage_impl import CloudStorageImpl


class Level3Tests(unittest.TestCase):
    """
    The test suit below includes 10 tests for Level 3.

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
    def test_level_3_case_01_different_users(self):
        self.assertTrue(self.storage.add_user("user1", 90))
        self.assertTrue(self.storage.add_user("user2", 60))
        self.assertEqual(self.storage.add_file_by("user1", "/file3.txt", 21), 69)
        self.assertIsNone(self.storage.add_file_by("user1", "/dir/file1.mp4", 70))
        self.assertEqual(self.storage.add_file_by("user2", "/dir/file1.mp4", 59), 1)
        self.assertEqual(self.storage.get_file_size("/file3.txt"), 21)
        self.assertEqual(self.storage.get_file_size("/dir/file1.mp4"), 59)

    @timeout(0.4)
    def test_level_3_case_02_user_limit(self):
        self.assertTrue(self.storage.add_file("/file", 80))
        self.assertTrue(self.storage.add_user("user", 30))
        self.assertEqual(self.storage.add_file_by("user", "/user/file", 30), 0)
        self.assertIsNone(self.storage.add_file_by("user", "/user/new_file", 20))
        self.assertEqual(self.storage.delete_file("/user/file"), 30)
        self.assertEqual(self.storage.add_file_by("user", "/user/new_file", 20), 10)
        self.assertIsNone(self.storage.get_file_size("/user/file"))
        self.assertEqual(self.storage.get_file_size("/user/new_file"), 20)

    @timeout(0.4)
    def test_level_3_case_03_duplicate_user(self):
        self.assertTrue(self.storage.add_user("user", 50))
        self.assertFalse(self.storage.add_user("user", 35))
        self.assertEqual(self.storage.add_file_by("user", "/user/file", 40), 10)
        self.assertFalse(self.storage.add_user("user", 45))
        self.assertTrue(self.storage.add_file("/another_file", 40))
        self.assertEqual(self.storage.add_file_by("user", "/user/another_file", 10), 0)
        expected = ["/another_file(40)", "/user/file(40)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)
        self.assertEqual(self.storage.delete_file("/user/file"), 40)
        self.assertFalse(self.storage.add_user("user", 60))
        self.assertTrue(self.storage.add_user("user2", 49))
        expected = ["/another_file(40)", "/user/another_file(10)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)

    @timeout(0.4)
    def test_level_3_case_04_merge_users(self):
        self.assertTrue(self.storage.add_user("user1", 40))
        self.assertTrue(self.storage.add_user("user2", 50))
        self.assertEqual(self.storage.add_file_by("user1", "/files/file1.txt", 30), 10)
        self.assertEqual(self.storage.add_file_by("user2", "/files/file2.mp4", 40), 10)
        self.assertEqual(self.storage.merge_user("user2", "user1"), 20)
        self.assertTrue(self.storage.add_file("/file", 50))
        self.assertIsNone(self.storage.add_file_by("user1", "/files/file3.mov", 20))
        self.assertEqual(self.storage.add_file_by("user2", "/files/file3.mov", 20), 0)
        self.assertEqual(self.storage.get_file_size("/files/file3.mov"), 20)
        expected = [
            "/files/file2.mp4(40)",
            "/files/file1.txt(30)",
            "/files/file3.mov(20)",
        ]
        self.assertEqual(self.storage.get_n_largest("/files", 3), expected)

    @timeout(0.4)
    def test_level_3_case_05_unexisting_users(self):
        self.assertTrue(self.storage.add_file("/files/file.txt", 4))
        self.assertTrue(self.storage.add_user("user", 40))
        self.assertIsNone(self.storage.add_file_by("user", "/files/file.txt", 20))
        self.assertIsNone(self.storage.add_file_by("userID", "/virus.bat", 4))
        self.assertIsNone(self.storage.add_file_by("use", "/util.sh", 6))
        self.assertIsNone(self.storage.get_file_size("/util.sh"))
        self.assertIsNone(self.storage.get_file_size("/use/util.sh"))
        self.assertIsNone(self.storage.delete_file("/util.sh"))
        self.assertIsNone(self.storage.delete_file("/virus.bat"))
        self.assertIsNone(self.storage.add_file_by("uzer", "/typos.txt", 3))

    @timeout(0.4)
    def test_level_3_case_06_merging_edge_cases(self):
        self.assertTrue(self.storage.add_user("user1", 30))
        self.assertEqual(self.storage.add_file_by("user1", "/files/file.txt", 20), 10)
        self.assertIsNone(self.storage.merge_user("user1", "user1"))
        self.assertIsNone(self.storage.merge_user("user1", "user3"))
        self.assertIsNone(self.storage.merge_user("user2", "user1"))
        self.assertIsNone(self.storage.add_file_by("user1", "/new_file", 20))
        self.assertIsNone(self.storage.merge_user("user1", "user2"))
        self.assertEqual(self.storage.get_file_size("/files/file.txt"), 20)

    @timeout(0.4)
    def test_level_3_case_07_users_mixed_1(self):
        self.assertTrue(self.storage.add_file("/dir/dir/file", 400))
        self.assertTrue(self.storage.add_user("user1", 40))
        self.assertEqual(self.storage.add_file_by("user1", "/dir/file.png", 35), 5)
        self.assertIsNone(self.storage.add_file_by("user2", "/dir/file2.png", 2))
        self.assertFalse(self.storage.add_user("user1", 40))
        self.assertTrue(self.storage.add_user("user2", 20))
        self.assertEqual(self.storage.add_file_by("user2", "/file.png", 15), 5)
        self.assertEqual(self.storage.merge_user("user1", "user2"), 10)
        self.assertIsNone(self.storage.merge_user("user2", "user1"))
        self.assertTrue(self.storage.add_user("user2", 10))
        self.assertEqual(self.storage.merge_user("user1", "user2"), 20)
        self.assertIsNone(self.storage.get_file_size("/dir/file2.png"))
        self.assertEqual(self.storage.add_file_by("user1", "/h.cpp", 16), 4)
        self.assertEqual(self.storage.delete_file("/file.png"), 15)
        self.assertIsNone(self.storage.add_file_by("user1", "/h.cpp", 16))

    @timeout(0.4)
    def test_level_3_case_08_users_mixed_2(self):
        self.assertTrue(self.storage.add_user("u3", 40))
        self.assertTrue(self.storage.add_user("u2", 35))
        self.assertTrue(self.storage.add_user("u1", 20))
        self.assertFalse(self.storage.get_n_largest("/", 3))
        self.assertIsNone(self.storage.add_file_by("u1", "/dir/top_file1", 38))
        self.assertIsNone(self.storage.add_file_by("u2", "/dir/top_file2", 38))
        self.assertEqual(self.storage.add_file_by("u3", "/dir/top_file3", 38), 2)
        self.assertIsNone(self.storage.add_file_by("u1", "/dir/dir/top_file1", 33))
        self.assertEqual(self.storage.add_file_by("u2", "/dir/dir/top_file2", 33), 2)
        self.assertIsNone(self.storage.add_file_by("u3", "/dir/dir/top_file3", 33))
        expected = ["/dir/top_file3(38)", "/dir/dir/top_file2(33)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        self.assertEqual(self.storage.merge_user("u2", "u1"), 22)
        self.assertEqual(self.storage.add_file_by("u2", "/dir/new_top", 21), 1)
        expected = ["/dir/top_file3(38)", "/dir/dir/top_file2(33)", "/dir/new_top(21)"]
        self.assertEqual(self.storage.get_n_largest("/dir", 3), expected)
        self.assertTrue(self.storage.add_user("u1", 50))
        self.assertEqual(self.storage.add_file_by("u1", "/dir/last_file", 30), 20)
        expected = [
            "/dir/top_file3(38)",
            "/dir/dir/top_file2(33)",
            "/dir/last_file(30)",
            "/dir/new_top(21)",
        ]
        self.assertEqual(self.storage.get_n_largest("/dir", 5), expected)

    @timeout(0.4)
    def test_level_3_case_09_users_mixed_3(self):
        self.assertTrue(self.storage.add_user("u1", 30))
        self.assertTrue(self.storage.add_user("u2", 35))
        self.assertTrue(self.storage.add_user("u3", 20))
        self.assertEqual(self.storage.add_file_by("u1", "/file1.txt", 2), 28)
        self.assertEqual(self.storage.add_file_by("u1", "/file2.mp3", 5), 23)
        self.assertEqual(self.storage.add_file_by("u1", "/dir/file3.mov", 20), 3)
        self.assertEqual(self.storage.merge_user("u2", "u1"), 38)
        self.assertEqual(self.storage.merge_user("u3", "u2"), 58)
        self.assertIsNone(self.storage.merge_user("u1", "u3"))
        self.assertIsNone(self.storage.add_file_by("u1", "/file4", 1))
        self.assertIsNone(self.storage.add_file_by("u3", "/file4", 60))
        self.assertEqual(self.storage.delete_file("/dir/file3.mov"), 20)
        self.assertEqual(self.storage.add_file_by("u3", "/file4", 60), 18)
        expected = ["/file4(60)", "/file2.mp3(5)"]
        self.assertEqual(self.storage.get_n_largest("/", 2), expected)

    @timeout(0.4)
    def test_level_3_case_10_users_mixed_4(self):
        self.assertTrue(self.storage.add_user("user1", 200))
        self.assertTrue(self.storage.add_user("user2", 50))
        self.assertEqual(self.storage.add_file_by("user1", "/file1.txt", 4), 196)
        self.assertEqual(self.storage.add_file_by("user1", "/file2.mp4", 38), 158)
        self.assertEqual(self.storage.add_file_by("user1", "/dir1/file3", 17), 141)
        self.assertEqual(self.storage.add_file_by("user1", "/dir1/file4.txt", 6), 135)
        self.assertEqual(
            self.storage.add_file_by("user1", "/dir1/deep_dir/file5.mkv", 40), 95
        )
        self.assertEqual(self.storage.add_file_by("user1", "/dir2/file6.mov", 15), 80)
        expected = ["/dir1/deep_dir/file5.mkv(40)", "/file2.mp4(38)", "/dir1/file3(17)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertIsNone(self.storage.add_file_by("user2", "/dir1/file3", 17))
        self.assertIsNone(self.storage.add_file_by("user2", "/dir2/file6.mov", 15))
        self.assertEqual(self.storage.delete_file("/dir1/deep_dir/file5.mkv"), 40)
        self.assertEqual(self.storage.delete_file("/file2.mp4"), 38)
        expected = ["/dir1/file3(17)", "/dir2/file6.mov(15)", "/dir1/file4.txt(6)"]
        self.assertEqual(self.storage.get_n_largest("/", 3), expected)
        self.assertFalse(self.storage.add_file("/file1.txt", 3))
        self.assertEqual(self.storage.add_file_by("user2", "/file2.mp4", 37), 13)
        self.assertEqual(self.storage.merge_user("user1", "user2"), 171)
        expected = ["/dir1/file3(17)", "/dir1/file4.txt(6)"]
        self.assertEqual(self.storage.get_n_largest("/dir1", 2), expected)
