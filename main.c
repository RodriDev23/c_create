#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_folder(char *name_project) {
    char space_name[150];
    snprintf(space_name, sizeof(space_name), "mkdir %s", name_project);
    system(space_name);
    return 0;
}

int create_file(char *name_project) {
    char path[200];
    snprintf(path, sizeof(path), "%s/compile_main.sh", name_project);

    FILE *compile_file = fopen(path, "w");
    if (compile_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char *compile_text =
        "#!/bin/bash\n"
        "\n"
        "gcc main.c -o main\n"
        "\n"
        "if [ $? -eq 0 ]; then\n"
        "    echo \"Compile it successfully\"\n"
        "else\n"
        "    echo \"Compilation failed\"\n"
        "    exit 1\n"
        "fi\n"
        "\n"
        "./main\n";

    fprintf(compile_file, "%s", compile_text);
    fclose(compile_file);
    return 0;
}

int main() {
    char name_project[150];
    printf("Enter the name of your project: ");
    scanf("%s", name_project); // No need to limit scanf with a length

    create_folder(name_project);
    create_file(name_project);

    return 0;
}

