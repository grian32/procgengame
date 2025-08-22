#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "camera.h"
#include "movement.h"

int main(void) {
    InitWindow(1024, 1024, "Proc Gen Game");

    DisableCursor();

    Camera3D camera = { 0 };

    camera.position = (Vector3){0.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Texture2D grassTex = LoadTexture("../grass.png");
    Mesh grassCubeMesh = GenMeshCube(1.0f, 1.0f, 1.0f);
    UploadMesh(&grassCubeMesh, false);
    Model grassModel = LoadModelFromMesh(grassCubeMesh);

    Texture2D somethingTex = LoadTexture("../something.png");
    Mesh somethingCubeMesh = GenMeshCube(1.0f, 1.0f, 1.0f);
    UploadMesh(&somethingCubeMesh, false);
    Model somethingModel = LoadModelFromMesh(somethingCubeMesh);

    grassModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = grassTex;
    somethingModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = somethingTex;

    srand(time(NULL));

    int capacity = 20;
    int *xArr = malloc(capacity * sizeof(int));
    int *zArr = malloc(capacity * sizeof(int));

    int count = 0;

    for (int i = 0; i < 20; i++) {
        if (rand() % 2 == 0) {
            int x = rand() % 20;
            xArr[count++] = x;
            int z = rand() % 20;
            zArr[count]= z;
        }
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        PUpdateCamera(&camera);
        UpdateMovement(&camera);

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        for (int x = 0; x <= 20; x++) {
            for (int z = 0; z <= 20; z++) {
                DrawModel(grassModel, (Vector3){(float)x, 0.0f, (float)z}, 1.0f, WHITE);
            }
        }

        for (int i = 0; i < count; i++) {
            DrawModel(somethingModel, (Vector3){(float)xArr[i], 1.0f, (float)zArr[i]}, 1.0f, WHITE);
        }

        EndMode3D();

        EndDrawing();
    }

    free(xArr);
    free(zArr);

    UnloadTexture(grassTex);
    UnloadTexture(somethingTex);

    UnloadModel(grassModel);
    UnloadModel(somethingModel);

    CloseWindow();
    return 0;
}