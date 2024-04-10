#[derive(Debug)]
struct Rectangle {
    width: i32,
    height: i32,
}

impl Rectangle {
    fn area(&self) -> i32 {
        self.width * self.height
    }
    
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    fn double(&mut self) {
        self.width *= 2;
        self.height *= 2;
    }
}

fn main () {
    let mut rect1 = Rectangle {
        width: 30,
        height: 50
    };

    println!(
        "The area of the rectangle is {} square pixels.",
        rect1.area()
    );

    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    // heres how to change
    rect1.double();
    println!(
        "The new area of the rectangle is {} square pixels.",
        rect1.area()
    );

}

