from collections import Counter

def get_average(marks):
    """Function to calculate average score of the class"""
    total_marks = sum(marks)
    total_students = len(marks)
    average = total_marks / total_students
    return average

def get_highest_lowest(marks):
    """Function to find the highest and lowest scores"""
    highest_score = max(marks)
    lowest_score = min(marks)
    return highest_score, lowest_score

def count_absent(marks, absent_marker=-1):
    """Function to count the number of students who were absent"""
    return marks.count(absent_marker)

def mark_with_highest_frequency(marks):
    """Function to find the mark with highest frequency"""
    mark_counts = Counter(marks)
    most_common_mark, frequency = mark_counts.most_common(1)[0]
    return most_common_mark, frequency

def main():
    # Input: Number of students
    N = int(input("Enter the number of students: "))
    
    marks = []
    
    # Input: Marks of each student
    for i in range(N):
        mark = int(input(f"Enter marks for student {i+1} (enter -1 for absent): "))
        marks.append(mark)

    # Compute the average score of the class
    average_score = get_average(marks)
    print(f"\nAverage score of the class: {average_score:.2f}")
    
    # Compute the highest and lowest score
    highest_score, lowest_score = get_highest_lowest(marks)
    print(f"Highest score in the class: {highest_score}")
    print(f"Lowest score in the class: {lowest_score}")
    
    # Count the students who were absent
    absent_count = count_absent(marks)
    print(f"Number of students who were absent: {absent_count}")
    
    # Find the mark with the highest frequency
    most_common_mark, frequency = mark_with_highest_frequency(marks)
    print(f"Mark with the highest frequency: {most_common_mark} (appears {frequency} times)")

if __name__ == "__main__":
    main()
