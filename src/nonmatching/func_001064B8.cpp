/* fuzzy: 96.6 */
extern "C" bool func_00106420(const char*, const char*);
extern "C" int func_00331BB8(const char*);

/* Looks up "name=value" / "name =value" / "name = value" style options in argv. Every path increments the
   index once per argument: the game's found paths branch to the single loop increment (0x00106544
   `b 0x001065A4` with `addiu $s1, $v0, 0x1` in its delay slot; 0x001065A4 `addiu $s2, $s2, 0x1`), so the
   value argument is not skipped. */
const char* func_001064B8(const char* name, int argc, char** argv)
{
    const char* result = 0;
    for (int i = 0; i < argc; i++) {
        if (func_00106420(argv[i], name)) {
            char* arg;
            int len = func_00331BB8(name);
            arg = argv[i];
            if (arg[len] == '=') {
                if (arg[len + 1]) {
                    result = &arg[len + 1];
                } else if (i < argc - 1) {
                    result = argv[i + 1];
                }
            } else if (arg[len] == 0 && i < argc - 1) {
                const char* q = argv[i + 1];
                if (*q == '=') {
                    if (q[1] == 0) {
                        if (i < argc - 2) {
                            result = argv[i + 2];
                        }
                    } else {
                        result = q + 1;
                    }
                }
            }
        }
    }
    return result;
}
