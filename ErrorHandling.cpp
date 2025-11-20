fn read_file(path: &str) -> Result<String, std::io::Error> {
    std::fs::read_to_string(path)
}

fn main() {
    match read_file("data.txt") {
        Ok(content) => println!("{}", content),
        Err(e) => println!("Error: {}", e),
    }
}
