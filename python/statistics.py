
class StatisticsCalculator:
    def __init__(self, numbers):
        if not numbers:
            raise ValueError("Dataset cannot be empty")
        self._numbers = list(numbers)

    def calculate_mean(self):
        return sum(self._numbers) / len(self._numbers)

    def calculate_median(self):
        sorted_numbers = sorted(self._numbers)
        n = len(sorted_numbers)
        middle = n // 2

        if n % 2 == 1:
            return float(sorted_numbers[middle])

        return (
            sorted_numbers[middle - 1]
            + sorted_numbers[middle]
        ) / 2

    def calculate_mode(self):
        frequencies = {}

        for number in self._numbers:
            frequencies[number] = frequencies.get(number, 0) + 1

        max_count = max(frequencies.values())

        if max_count == 1:
            return []

        return sorted(
            number
            for number, count in frequencies.items()
            if count == max_count
        )

    def display_results(self):
        print("Python - Object-Oriented Statistics")
        print("Dataset:", ", ".join(map(str, self._numbers)))
        print(f"Mean: {self.calculate_mean():.2f}")
        print(f"Median: {self.calculate_median():.2f}")

        modes = self.calculate_mode()
        if modes:
            print("Mode:", ", ".join(map(str, modes)))
        else:
            print("Mode: No mode (all values occur once)")


if __name__ == "__main__":
    data = [4, 2, 7, 4, 9, 2, 4, 6, 2, 8]
    calculator = StatisticsCalculator(data)
    calculator.display_results()
