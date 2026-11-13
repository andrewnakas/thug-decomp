/* fuzzy: 69.6 */
struct C_00128078 {
    int GetWord(char* word, const char** p);
};

int C_00128078::GetWord(char* word, const char** p)
{
    int more = 1;
    int ret = 0;
    do {
        const char* s = *p;
        char c = *s;
        switch (c) {
        case ' ':
            *word = *s;
            more = 0;
            break;
        case '\\':
            *p = s + 1;
            if (s[1] == '_') {
                *word = ' ';
            } else if (s[1] == 'n') {
                *p = s + 2;
                ret = 1;
                more = 0;
                continue;
            } else {
                *word = c;
                word++;
                *word = **p;
            }
            break;
        case 0:
            ret = 2;
            more = 0;
            continue;
        default:
            *word = *s;
            break;
        }
        word++;
        (*p)++;
    } while (more);
    *word = 0;
    return ret;
}
