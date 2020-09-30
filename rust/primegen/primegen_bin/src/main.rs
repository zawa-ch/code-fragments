
extern crate primegen;

fn main() {
    let primes = primegen::PrimeGenerator::new();
    for prime in primes {
        print!("{} ", prime);
    }
}
