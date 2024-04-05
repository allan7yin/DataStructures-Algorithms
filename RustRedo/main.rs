fn main() {
    let mut r1 = String::from("allan");
    mutateString(&mut r1);
    printString(r1);
    println!("Back in the main function!{r1}");
}

fn mutateString(str: &mut String) {
    str.push_str(" woohooo");
}

fn printString(str: String) {
    println!("{}", str);
    println!("Passed {str} by reference and printed")
}