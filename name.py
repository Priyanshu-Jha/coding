# Prompt the user for a full name
full_name = input("Enter your full name: ")

# Split the name into words and join them without spaces
single_name = ''.join(full_name.split())

# Output the result
print(f"Single connected name: {single_name}")
