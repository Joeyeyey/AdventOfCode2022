INPUT_FILE = "input.txt"

if __name__ == "__main__":

    elves_and_calories = [];
    with open(INPUT_FILE) as input_file:
        calories = []
        for line in input_file:
            if line.strip() == "":
                elves_and_calories.append(calories)
                calories.clear()
            else:
                calories.append(int(line))

    print(f"Elves & Calories\n{elves_and_calories}")
