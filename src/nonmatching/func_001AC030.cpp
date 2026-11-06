/* fuzzy: 48.0 */
// One entry of the trick history ring (100 entries, newest at m_head).
struct Hist_001AC030 {
    unsigned int time;
    int type;
    unsigned int id;
    int pad;
    int used;
    unsigned int flags;
};

struct Idx3_001AC030 {
    int v[3];
};

extern Idx3_001AC030 D_00362970;

struct Node_001AC030 {
    char pad0[8];
    unsigned int m8;
    Node_001AC030* mC;
};

struct Rec_001AC030 {
    char pad0[0x524];
    int m524;
    int m528;
    bool Busy()
    {
        if (m524 || m528)
            return true;
        return false;
    }
};

extern "C" unsigned int func_0010FC30();
extern "C" Node_001AC030* func_001E6E90(void* script, Node_001AC030* prev);
extern "C" int func_001AB330(unsigned int id);

struct Combo_001AC030;

static inline unsigned int Since_001AC030(unsigned int t)
{
    return func_0010FC30() - t;
}

extern "C" unsigned int func_001ABDE8(Combo_001AC030* self, Node_001AC030* args, int n, unsigned int* ids);
extern "C" int func_001ABFF8(Combo_001AC030* self, unsigned int id);
extern "C" int func_001ABB20(Combo_001AC030* self, unsigned int id, unsigned int window, unsigned int mask);
extern "C" int func_001ABC58(Combo_001AC030* self, unsigned int id0, unsigned int id1, unsigned int window,
                             unsigned int mask);
extern "C" void func_001AB9B0(Combo_001AC030* self, int flags);
extern "C" void func_001ABE98(Combo_001AC030* self, unsigned int* ids);
extern "C" void func_001AB950(Combo_001AC030* self);

struct Combo_001AC030 {
    char pad0[0x24];
    Rec_001AC030* m24;
    char pad28[0x3C - 0x28];
    Hist_001AC030 m_hist[100];
    unsigned short m_count;
    unsigned short m_head;
    unsigned int m9A0[3];
    int Check(void* script, int flags, unsigned int mask);
};

int Combo_001AC030::Check(void* script, int flags, unsigned int mask)
{
    unsigned int ids[3];

    if (!script)
        return 0;
    if (m24->Busy())
        return 0;
    Node_001AC030* args = func_001E6E90(script, 0);
    if (!args)
        return 0;
    unsigned int kind = args->m8;
    args = args->mC;
    for (int i = 2; i >= 0; i--) {
        ids[i] = 0;
    }

    switch (kind) {
    case 0x14FE9B7D: {
        int idx;
        int k;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        if (func_001ABFF8(this, ids[1])) {
            idx = m_head;
            for (k = 0; k < m_count; k++) {
                if (m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    m_hist[idx].used = 1;
                    break;
                }
                idx--;
                if (idx < 0)
                    idx += 100;
            }
            if (func_001ABB20(this, ids[0], window, mask))
                goto ok_flags;
            goto fail;
        }
        if (func_001ABC58(this, ids[0], ids[1], window, mask))
            goto ok_flags;
        goto fail;
    }

    case 0xFFB718BD: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[1]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x2C434C90: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[1]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    stage = 2;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 2) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x696E5E66: {
        int idx;
        int k;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        // found starts as the game's {-1, -1, -1} initialiser.
        Idx3_001AC030 found = D_00362970;
        int n = 0;
        idx = m_head;
        for (k = 0; k < m_count; k++) {
            if (!(m_hist[idx].flags & mask) && m_hist[idx].id != 0xBC6B118F && m_hist[idx].id != 0xE3006FC4 &&
                m_hist[idx].id != 0x85981897 &&
                m_hist[idx].id != 0x4B358AEB) {
                found.v[n] = idx;
                n++;
                if (n == 3)
                    break;
            }
            idx--;
            if (idx < 0)
                idx += 100;
        }
        if (found.v[0] == -1 || found.v[1] == -1 || found.v[2] == -1)
            return 0;
        if (!(Since_001AC030(m_hist[found.v[0]].time) < window))
            return 0;
        if (!(Since_001AC030(m_hist[found.v[1]].time) < window))
            return 0;
        if (!(Since_001AC030(m_hist[found.v[2]].time) < window))
            return 0;
        if (m_hist[found.v[0]].type != 2 || m_hist[found.v[0]].id != ids[1])
            goto fail;
        if (m_hist[found.v[1]].type != 1 || m_hist[found.v[1]].id != m_hist[found.v[0]].id)
            goto fail;
        if (m_hist[found.v[2]].type != m_hist[found.v[0]].type || m_hist[found.v[2]].id != ids[0])
            goto fail;
        m_hist[found.v[0]].used = 1;
        m_hist[found.v[1]].used = 1;
        m_hist[found.v[2]].used = 1;
        goto ok_flags;
    }

    case 0x3C3028F4: {
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        if (!func_001ABFF8(this, ids[0]))
            goto fail;
        if (!func_001ABFF8(this, ids[1]))
            goto fail;
        if (func_001ABC58(this, ids[0], ids[1], window, mask))
            goto ok_flags;
        goto fail;
    }

    case 0x7D482318: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x3F369070: {
        int idx;
        int k;
        int got0 = 0;
        int got1 = 0;
        int done = 0;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        idx = m_head;
        for (k = 0; k < m_count; k++) {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (!(m_hist[idx].flags & mask) && m_hist[idx].id == ids[0]) {
                if (m_hist[idx].type == 2) {
                    got0 = 0;
                    m_hist[idx].used = 1;
                    got1 = 0;
                } else if (m_hist[idx].type == 1) {
                    m_hist[idx].used = 1;
                    if (got1) {
                        done = 1;
                        break;
                    }
                    got0 = 1;
                }
            }
            if (!(m_hist[idx].flags & mask) && m_hist[idx].id == ids[1]) {
                if (m_hist[idx].type == 2) {
                    got0 = 0;
                    m_hist[idx].used = 1;
                    got1 = 0;
                } else if (m_hist[idx].type == 1) {
                    m_hist[idx].used = 1;
                    if (got0) {
                        done = 1;
                        break;
                    }
                    got1 = 1;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
        }
        if (!done)
            return 0;
        m_hist[idx].used = 1;
        goto ok_flags;
    }

    case 0xC1AD35C0: {
        int idx;
        int k;
        int stage;
        // ids[2], ids[1], ids[0] in order.
        unsigned int window = func_001ABDE8(this, args, 3, ids);
        stage = 0;
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    stage = 2;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 2) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x3FE7C311: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 3, ids);
        idx = m_head;
        if (!m_count)
            goto fail;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[1]) {
                    stage = 2;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 2) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    stage = 3;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 3) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0]) {
                    stage = 4;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 4) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0xA2E042D7: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 3, ids);
        idx = m_head;
        if (!m_count)
            goto fail;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                } else if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    stage = 2;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 1) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]) {
                    stage = 3;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 2) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2]) {
                    stage = 3;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 3) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0]) {
                    stage = 4;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 4) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    goto ok_flags;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x823B8342: {
        int idx;
        int k;
        unsigned int window = func_001ABDE8(this, args, 1, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                m_hist[idx].flags |= flags;
                goto ok;
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x61B8FCE2: {
        int idx;
        int k;
        unsigned int window = func_001ABDE8(this, args, 1, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0]) {
                m_hist[idx].flags |= flags;
                goto ok;
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x7FA5CDBB: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 1, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]) {
                    m_hist[idx].used = 1;
                    func_001AB9B0(this, flags);
                    return 1;
                }
            } else if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0]) {
                stage = 1;
                m_hist[idx].used = 1;
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0xF630DAE5: {
        int idx;
        int k;
        int stage = 0;
        unsigned int window = func_001ABDE8(this, args, 3, ids);
        if (!m_count)
            goto fail;
        idx = m_head;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (stage == 1) {
                if (!(m_hist[idx].flags & mask)) {
                    if (m_hist[idx].id == ids[1]) {
                        if (m_hist[idx].type == 1) {
                            stage = 2;
                            m_hist[idx].used = 1;
                        } else if (m_hist[idx].type == 2) {
                            return 0;
                        }
                    } else if (m_hist[idx].id == ids[0]) {
                        if (m_hist[idx].type == 1) {
                            stage = 3;
                            m_hist[idx].used = 1;
                        } else if (m_hist[idx].type == 2) {
                            return 0;
                        }
                    }
                }
            } else if (stage == 0) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2]) {
                    stage = 1;
                    m_hist[idx].used = 1;
                }
            } else if (stage == 2) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].id == ids[0]) {
                    if (m_hist[idx].type == 1) {
                        m_hist[idx].used = 1;
                        goto ok_flags;
                    }
                    if (m_hist[idx].type == 2)
                        return 0;
                }
            } else if (stage == 3) {
                if (!(m_hist[idx].flags & mask) && m_hist[idx].id == ids[1]) {
                    if (m_hist[idx].type == 1) {
                        m_hist[idx].used = 1;
                        goto ok_flags;
                    }
                    if (m_hist[idx].type == 2)
                        return 0;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0xAC2B1445: {
        int idx;
        int k;
        int g0 = 0;
        int g1 = 0;
        int t2 = 0;
        unsigned int window = func_001ABDE8(this, args, 3, ids);
        idx = m_head;
        if (!m_count)
            goto fail;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (!g0 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0])) {
                g0 = 1;
                m_hist[idx].used = 1;
            }
            if (!g1 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[1])) {
                g1 = 1;
                m_hist[idx].used = 1;
            }
            if (!t2 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[2])) {
                t2 = 1;
                m_hist[idx].used = 1;
            }
            if (g0 && !g1 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]))
                return 0;
            if (g1 && !g0 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]))
                return 0;
            if (g0 && g1 && t2)
                goto ok_flags;
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0x395EC2D4: {
        int idx;
        int k;
        int g0 = 0;
        int g1 = 0;
        unsigned int window = func_001ABDE8(this, args, 2, ids);
        idx = m_head;
        if (!m_count)
            goto fail;
        k = 0;
        do {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                return 0;
            if (!g0 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[0])) {
                g0 = 1;
                m_hist[idx].used = 1;
            }
            if (!g1 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 2 && m_hist[idx].id == ids[1])) {
                g1 = 1;
                m_hist[idx].used = 1;
            }
            if (g0 && !g1 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[0]))
                return 0;
            if (g1 && !g0 && (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1 && m_hist[idx].id == ids[1]))
                return 0;
            if (g0 && g1)
                goto ok_flags;
            idx--;
            if (idx < 0)
                idx += 100;
            k++;
        } while (k < m_count);
        goto fail;
    }

    case 0xB6258557: {
        int idx;
        int k;
        unsigned int last = 0;
        int found = 0;
        int at = 0;
        for (int i = 0; i < 3; i++) {
            if (func_001AB330(m9A0[i]))
                last = m9A0[i];
        }
        unsigned int window = func_001ABDE8(this, args, 1, ids);
        idx = m_head;
        for (k = 0; k < m_count; k++) {
            if (!(Since_001AC030(m_hist[idx].time) < window))
                break;
            if (!(m_hist[idx].flags & mask) && m_hist[idx].type == 1) {
                found = 1;
                if (m_hist[idx].id == ids[0]) {
                    at = idx;
                } else if (func_001AB330(m_hist[idx].id)) {
                    if (m_hist[idx].id != last)
                        return 0;
                    m_hist[idx].used = 1;
                }
            }
            idx--;
            if (idx < 0)
                idx += 100;
        }
        if (!found)
            goto fail;
        m_hist[at].flags |= flags;
        goto ok_flags;
    }

    case 0xA8123ECF: {
        unsigned int a = args->m8;
        unsigned int b = args->mC->m8;
        unsigned int c = args->mC->mC->m8;
        int r = 0;
        if (func_001ABFF8(this, a) && func_001ABFF8(this, b)) {
            r = func_001ABFF8(this, c) != 0;
        }
        return r;
    }

    default:
        goto fail;
    }

ok_flags:
    func_001AB9B0(this, flags);
ok:
    func_001ABE98(this, ids);
    return 1;
fail:
    func_001AB950(this);
    return 0;
}
