struct Req_001116D0 {
    char pad[0x10];
    int m10;
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

struct Job_001116D0 {
    char pad[0x1C];
    int m1C;
    char pad20[0x3C - 0x20];
    int m3C;
};

extern "C" int func_00112238(Req_001116D0* req, Job_001116D0* job, int a, int b);
extern "C" int func_0010E4B0(Job_001116D0* job);

extern "C" void func_001116D0(Job_001116D0* job, int arg)
{
    Req_001116D0 req;
    req.m6C = 6;
    req.m10 = job->m3C;
    req.m14 = 2;
    req.m18 = arg;
    func_00112238(&req, job, 1, -1);
    if (job->m1C) {
        func_0010E4B0(job);
    }
}
