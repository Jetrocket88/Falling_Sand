#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_DIR "build/"
#define SRC_DIR "src/"
#define INCLUDE_DIR "include/"
#define LIB_DIR "lib/"

int main(int argc, char** argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "gcc", "-Wall", "-Wextra", "-o", BUILD_DIR"falling_sand", SRC_DIR"main.c");
    nob_cmd_append(&cmd, "-O1", "-Wno-missing-braces", "-I", "./"INCLUDE_DIR, "-L", "./"LIB_DIR);
    nob_cmd_append(&cmd, "-lraylib", "-lopengl32", "-lgdi32", "-lwinmm");
    if (!nob_cmd_run(&cmd))
        return 1;
    return 0;
}


