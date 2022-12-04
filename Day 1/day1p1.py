INPUT_FILE = "input.txt"

if __name__ == "__main__":

    max_calories = 0;
    curr_calories = 0;

    with open(INPUT_FILE) as input_file:
        for line in input_file:
            if line.strip() == "":
                if curr_calories > max_calories:
                    max_calories = curr_calories
                curr_calories = 0
            else:
                curr_calories += int(line)

    print(f"Max Calories: {max_calories}")
