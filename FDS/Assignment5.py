# Function to perform Insertion Sort
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to perform Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Perform a "gapped" insertion sort
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Main function
def main():
    # Taking input from the user (first-year percentages of students)
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        percentage = float(input(f"Enter the percentage for student {i+1}: "))
        percentages.append(percentage)
    
    # Display the unsorted array
    print("\nUnsorted Percentages: ", percentages)
    
    # Sorting using Insertion Sort
    insertion_sorted = percentages.copy()
    insertion_sort(insertion_sorted)
    print("\nPercentages after Insertion Sort: ", insertion_sorted)
    
    # Sorting using Shell Sort
    shell_sorted = percentages.copy()
    shell_sort(shell_sorted)
    print("\nPercentages after Shell Sort: ", shell_sorted)

if __name__ == "__main__":
    main()
