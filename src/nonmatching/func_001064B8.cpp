/* fuzzy: 57.4 */
extern "C" bool func_00106420(const char*, const char*);
extern "C" int func_00331BB8(const char*);

const char* func_001064B8(const char* name, int argc, char** argv)
{
    const char* result = 0;
    int i = 0;
    if (argc > 0) {
        char** a = argv;
        do {
            if (func_00106420(*a, name)) {
                int len = func_00331BB8(name);
                const char* p = &(*a)[len];
                if (*p == '=') {
                    if (p[1]) {
                        result = p + 1;
                        i++;
                    } else if (i < argc - 1) {
                        result = a[1];
                        i++;
                    }
                } else if (*p == 0 && i < argc - 1) {
                    const char* q = a[1];
                    if (*q == '=') {
                        if (q[1]) {
                            result = q + 1;
                            i++;
                        } else if (i < argc - 2) {
                            result = a[2];
                            i++;
                        }
                    }
                }
            }
            i++;
            a++;
        } while (i < argc);
    }
    return result;
}
