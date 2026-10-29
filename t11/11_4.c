#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct Rect {
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
} Rect;

void print_rect(const Rect* rect) {
    printf("Rect ID: %d\n", rect->id);
    printf("Coordinates: (%lf, %lf) to (%lf, %lf)\n", rect->x1, rect->y1, rect->x2, rect->y2);
}

bool input_rect(Rect* rect) {
    if (rect == NULL) {
        return false;
    }
    printf("Enter Rect ID: ");
    if (scanf("%d", &rect->id) != 1) {
        return false;
    }
    printf("Enter Coordinates (x1 y1 x2 y2): ");
    if (scanf("%lf %lf %lf %lf", &rect->x1, &rect->y1, &rect->x2, &rect->y2) != 4) {
        return false;
    }
    if (rect->x1 > rect->x2) {
        double temp = rect->x1;
        rect->x1 = rect->x2;
        rect->x2 = temp;
    }
    if (rect->y1 > rect->y2) {
        double temp = rect->y1;
        rect->y1 = rect->y2;
        rect->y2 = temp;
    }
    return true;
}

double rect_area(const Rect* rect) {
    if (rect == NULL) {
        return 0.0;
    }
    double width = fabs(rect->x2 - rect->x1);
    double height = fabs(rect->y2 - rect->y1);
    return width * height;
}

bool write_rect_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }
    int n;
    printf("Enter the number of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        return false;
    }

    for (int i = 0; i < n; i++) {
        Rect rect;
        if (!input_rect(&rect)) {
            fclose(file);
            return false;
        }
        fwrite(&rect, sizeof(Rect), 1, file);
    }
    fclose(file);
    return true;
}

int max_area_rect(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }

    Rect rect;
    int max_id = -1;
    double max_area = 0.0;
    while (fread(&rect, sizeof(Rect), 1, file) == 1) {
        double area = rect_area(&rect);
        if (area > max_area) {
            max_area = area;
            max_id = rect.id;
        }
    }
    fclose(file);
    return max_id;
}

bool remove_rect(const char* filename, int id) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    FILE* temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        fclose(file);
        return false;
    }

    Rect rect;
    bool found = false;
    while (fread(&rect, sizeof(Rect), 1, file) == 1) {
        if (rect.id == id) {
            found = true;
            continue;
        }
        fwrite(&rect, sizeof(Rect), 1, temp);
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove(filename);
        rename("temp.bin", filename);
    } else {
        remove("temp.bin");
    }
    return found;
}

int main() {
    const char* filename = "rectangles.bin";

    if (!write_rect_file(filename)) {
        printf("Failed to write rectangles to file.\n");
        return 1;
    }

    int max_id = max_area_rect(filename);
    if (max_id != -1) {
        printf("Rectangle with max area has ID: %d\n", max_id);
    } else {
        printf("Failed to find rectangle with max area.\n");
    }

    int remove_id;
    printf("Enter ID of rectangle to remove: ");
    if (scanf("%d", &remove_id) == 1) {
        if (remove_rect(filename, remove_id)) {
            printf("Rectangle with ID %d removed successfully.\n", remove_id);
        } else {
            printf("Rectangle with ID %d not found.\n", remove_id);
        }
    }

    return 0;
}