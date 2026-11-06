int func_001A1448(int type, float v)
{
    int r = 0;
    switch (type) {
    case 0:
        if (v == 0.05f) r = 0;
        else if (v == 0.1f) r = 1;
        else if (v == 10.1f) r = 2;
        break;
    case 1:
        if (v == 0.04f) r = 0;
        else if (v == 10.1f) r = 1;
        break;
    case 2:
        if (v == 0.0022f) r = 0;
        else if (v == 20.0f) r = 1;
        break;
    case 3:
        if (v == 0.0017f) r = 0;
        else if (v == 10.0f) r = 1;
        break;
    case 4:
        if (v == 1.5f) r = 0;
        else if (v == 1.0f) r = 1;
        break;
    }
    return r;
}
