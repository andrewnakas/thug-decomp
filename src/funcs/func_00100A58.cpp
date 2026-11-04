extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

struct Vec {
    float v[4];
    float& operator[](int i) { return v[i]; }
};

struct Mat {
    Vec r[4];
    Vec& operator[](int i) { return r[i]; }
};

extern "C" Mat* func_00100A58(Mat* m, int axis, float angle)
{
    int a = (axis + 1) % 3;
    int b = (axis + 2) % 3;
    float s = func_00341068(angle);
    float c = func_00340F60(angle);
    Mat& M = *m;
    M[0][0] = 1.0f; M[0][1] = 0.0f; M[0][2] = 0.0f; M[0][3] = 0.0f;
    M[1][0] = 0.0f; M[1][1] = 1.0f; M[1][2] = 0.0f; M[1][3] = 0.0f;
    M[2][0] = 0.0f; M[2][1] = 0.0f; M[2][2] = 1.0f; M[2][3] = 0.0f;
    M[3][0] = 0.0f; M[3][1] = 0.0f; M[3][2] = 0.0f; M[3][3] = 1.0f;
    M[a][a] = c;
    M[a][b] = s;
    M[b][a] = -s;
    M[b][b] = c;
    return m;
}
