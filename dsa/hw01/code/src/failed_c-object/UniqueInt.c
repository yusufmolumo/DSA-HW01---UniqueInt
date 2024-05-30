#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_VALUE -1023
#define MAX_VALUE 1023
#define RANGE (MAX_VALUE - MIN_VALUE + 1)

// Function to check if a string contains only whitespace characters (unchanged)
int isAllWhitespace(char *str) {
  // ... (same implementation as before)
}

// Function to check if a string contains a valid integer within the given range (unchanged)
int isValidInteger(char *str) {
  // ... (same implementation as before)
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  char *input_file_name = argv[1]; // Input file name
  char output_file_name[100]; // Output file name

  // Construct output file name
  sprintf(output_file_name, "%s_results.txt", input_file_name);

  FILE *input_file, *output_file;
  char line[100];

  // Array to track occurrences of integers within the range
  int occurrences[RANGE] = {0}; // Initialize all occurrences to 0

  // Open input file for reading
  input_file = fopen(input_file_name, "r");
  if (input_file == NULL) {
    printf("Error opening input file '%s'.\n", input_file_name);
    return 1;
  }

  // Read each line from input file
  while (fgets(line, sizeof(line), input_file) != NULL) {
    // Remove trailing newline character
    line[strcspn(line, "\n")] = '\0';

    // Skip lines with no inputs or only whitespaces (unchanged)
    if (isAllWhitespace(line)) {
      continue;
    }

    // Skip lines containing non-integer values or integers out of range (unchanged)
    if (!isValidInteger(line)) {
      continue;
    }

    // Extract integer from line and update occurrences array
    int num = atoi(line);
    occurrences[num - MIN_VALUE]++; // Adjust index to start from 0
  }

  // Close input file
  fclose(input_file);

  // Open output file for writing
  output_file = fopen(output_file_name, "w");
  if (output_file == NULL) {
    printf("Error opening output file '%s'.\n", output_file_name);
    return 1;
  }

  // Write unique integers to output file (iterate through occurrences array)
  int unique_count = 0;
  for (int i = 0; i < RANGE; i++) {
    if (occurrences[i] == 1) {
      fprintf(output_file, "%d\n", i + MIN_VALUE); // Adjust index back to original value
      unique_count++;
    }
  }

  // Close output file
  fclose(output_file);

  if (unique_count == 0) {
    printf("No unique integers found in the input file.\n");
  } else {
    printf("Unique integers have been written to output file '%s' in increasing order.\n", output_file_name);
  }

  return 0;
}
