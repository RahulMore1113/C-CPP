# Function to implement Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function to implement Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                # Swap if the element is greater than the next
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Function to display top five scores
def display_top_five_scores(arr):
    # Sorting the array in descending order to get the top scores
    arr.sort(reverse=True)
    print("Top 5 Scores:")
    for i in range(min(5, len(arr))):  # To handle cases where there are less than 5 students
        print(f"{i+1}. {arr[i]}%")

# Main function to test the code
def main():
    # Example student percentages (floating point numbers)
    student_percentages = [76.5, 85.0, 92.3, 60.0, 70.8, 88.5, 91.7, 84.5, 77.3, 95.4]
    
    # Clone of original list for selection sort
    selection_sorted = student_percentages.copy()
    
    # Clone of original list for bubble sort
    bubble_sorted = student_percentages.copy()
    
    print("Original Student Percentages:")
    print(student_percentages)
    
    # Sorting using Selection Sort
    selection_sort(selection_sorted)
    print("\nSorted using Selection Sort (Ascending Order):")
    print(selection_sorted)
    
    # Sorting using Bubble Sort
    bubble_sort(bubble_sorted)
    print("\nSorted using Bubble Sort (Ascending Order):")
    print(bubble_sorted)
    
    # Display Top 5 Scores after sorting
    display_top_five_scores(selection_sorted)

# Run the program
if __name__ == "__main__":
    main()
