struct File_00110280 {
    int m0;
    int pos;
    int size;
    char pad[0xC80C - 0xC];
    int bufPos;
};

extern "C" int func_00110280(File_00110280* f, long offset, int whence)
{
    int old = f->pos;
    int prev = f->bufPos;
    int start = old - prev;
    f->bufPos = 0xC800;
    int invalid = 0;
    if (prev == 0xC800) {
        invalid = 1;
    }
    switch (whence) {
    case 1:
        if (old + offset >= start && old + offset < start + 0xC800) {
            f->bufPos = old + (int)offset - start;
            f->pos += (int)offset;
            goto done;
        }
        f->pos += (int)offset;
        if (f->pos < 0 || f->pos > f->size) {
            f->pos = -1;
        }
        break;
    case 2:
        f->pos = f->size - (int)offset;
        if (f->pos < 0 || f->pos > f->size) {
            f->pos = -1;
        }
        break;
    case 0:
        f->pos = (int)offset;
        if (f->pos < 0 || f->pos > f->size) {
            f->pos = -1;
        }
        break;
    default:
        return -1;
    }
done:
    if (invalid) {
        f->bufPos = 0xC800;
    }
    if (f->pos == -1) {
        f->pos = old;
        f->bufPos = 0xC800;
        return -1;
    }
    return 0;
}
