
/// 素数を生成するイテレータ。
pub struct PrimeGenerator {
    current: u128
}

impl PrimeGenerator {
    /// このイテレータの新しいインスタンスを生成します。
    pub fn new() -> Self { PrimeGenerator { current: 1 } }
    /// 現在生成されている素数を取得します。
    pub fn current(&self) -> u128 { self.current }
}

impl Iterator for PrimeGenerator {
    type Item = u128;
    fn next(&mut self) -> Option<Self::Item> {
        self.current += 1;
        let mut ceiling = self.current / 2;
        let mut divider = 2;
        while divider <= ceiling {
            if (self.current % divider) == 0 {
                self.current += 1;
                ceiling = self.current / 2;
                divider = 2;
            }
            else { divider += 1; }
        };
        Some(self.current)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
        let mut primes = PrimeGenerator::new();

        assert_eq!(primes.next(), Some(2));
        assert_eq!(primes.next(), Some(3));
        assert_eq!(primes.next(), Some(5));
        assert_eq!(primes.next(), Some(7));
        assert_eq!(primes.next(), Some(11));
    }
}
