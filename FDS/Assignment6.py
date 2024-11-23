def quick_sort(arr):
    """Sorts an array using the Quick Sort algorithm."""
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def display_top_scores(arr, top_n=5):
    """Displays the top N scores from the sorted list."""
    sorted_arr = quick_sort(arr)
    top_scores = sorted_arr[-top_n:]  # Get the last 'top_n' scores
    print(f"Top {top_n} scores (in ascending order):")
    for score in top_scores:
        print(f"{score:.2f}")

def main():
    # Input: First year percentage of students
    # Example data (you can replace it with actual student data)
    students_percentages = [
        75.5, 89.2, 62.5, 91.3, 78.8,
        84.7, 56.3, 99.4, 63.2, 88.1,
        92.6, 80.9, 77.0, 91.0, 66.3
    ]
    
    # Display top 5 scores
    display_top_scores(students_percentages)

if __name__ == "__main__":
    main()
