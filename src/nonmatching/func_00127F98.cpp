/* fuzzy: 33.9 */
struct C_00128078 {
    int GetWord(char* word, const char** p);
};

int C_00128078::GetWord(char* word, const char** p)
{
    int ret = 0;
    int more = 1;
    do {
        const char* s = *p;
        switch (*s) {
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
                *word = *s;
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
