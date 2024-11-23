# Sample Data: 
# Group A: Students who play cricket
# Group B: Students who play badminton
# Group C: Students who play football

group_A = {"Alice", "Bob", "Charlie", "David", "Eve"}
group_B = {"Alice", "Frank", "George", "Charlie", "Helen"}
group_C = {"David", "Eve", "George", "Ivy"}

# a) List of students who play both cricket and badminton
def players_cricket_and_badminton():
    return group_A.intersection(group_B)

# b) List of students who play either cricket or badminton but not both
def players_cricket_or_badminton_not_both():
    return group_A.symmetric_difference(group_B)

# c) Number of students who play neither cricket nor badminton
def players_neither_cricket_nor_badminton():
    all_students = group_A.union(group_B).union(group_C)
    students_playing_cricket_or_badminton = group_A.union(group_B)
    return len(all_students - students_playing_cricket_or_badminton)

# d) Number of students who play cricket and football but not badminton
def players_cricket_and_football_not_badminton():
    cricket_and_football = group_A.intersection(group_C)
    return len(cricket_and_football - group_B)

# Display the results
print("a) Students who play both cricket and badminton:", players_cricket_and_badminton())
print("b) Students who play either cricket or badminton but not both:", players_cricket_or_badminton_not_both())
print("c) Number of students who play neither cricket nor badminton:", players_neither_cricket_nor_badminton())
print("d) Number of students who play cricket and football but not badminton:", players_cricket_and_football_not_badminton())
