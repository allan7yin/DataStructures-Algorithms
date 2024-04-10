// structs 
#[derive(Clone, Debug)]
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: i32,
}


fn main() {
    let user1 = User {
        active: true,
        username: String::from("AllanYin"),
        email: String::from("a7yin@uwaterloo.ca"),
        sign_in_count: 1,
    };

    // since they are strings, need to clone. If it was only primitives, could just assign with ..user1, and they would be cloned
    let user2 = User {
        email: String::from("allanyin17@gmail.com"),
        ..user1.clone()
    };

    println!("{:?}", user1);
    println!("{:?}", user2);
}