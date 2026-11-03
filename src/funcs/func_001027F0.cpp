#include "game/vector.h"

struct Box_001027F0 {
    Vector min;
    Vector max;
    bool Contains(const Vector& p) const
    {
        return min.x <= p.x && min.y <= p.y && min.z <= p.z && p.x <= max.x && p.y <= max.y && p.z <= max.z;
    }
};

struct Seg_001027F0 {
    Vector p0;
    Vector p1;
};

extern "C" int func_001027F0(Box_001027F0* box, Seg_001027F0* seg, Vector* point, Vector* normal)
{
    bool in0 = seg->p0.x >= box->min.x && seg->p0.y >= box->min.y && seg->p0.z >= box->min.z
            && seg->p0.x <= box->max.x && seg->p0.y <= box->max.y && seg->p0.z <= box->max.z;
    bool in1 = seg->p1.x >= box->min.x && seg->p1.y >= box->min.y && seg->p1.z >= box->min.z
            && seg->p1.x <= box->max.x && seg->p1.y <= box->max.y && seg->p1.z <= box->max.z;
    if (in0 && in1) {
        return 0;
    }
    if (seg->p0.y > box->max.y && seg->p1.y > box->max.y) {
        return 0;
    }
    if (seg->p0.y < box->min.y && seg->p1.y < box->min.y) {
        return 0;
    }
    if (seg->p0.x > box->max.x && seg->p1.x > box->max.x) {
        return 0;
    }
    if (seg->p0.x < box->min.x && seg->p1.x < box->min.x) {
        return 0;
    }
    if (seg->p0.z > box->max.z && seg->p1.z > box->max.z) {
        return 0;
    }
    if (seg->p0.z < box->min.z && seg->p1.z < box->min.z) {
        return 0;
    }
    float dx = seg->p1.x - seg->p0.x;
    float dy = seg->p1.y - seg->p0.y;
    float dz = seg->p1.z - seg->p0.z;
    if (dx == 0.0f) {
        dx = 0.000001f;
    }
    if (dy == 0.0f) {
        dy = 0.000001f;
    }
    if (dz == 0.0f) {
        dz = 0.000001f;
    }
    Vector v;
    if (box->max.x < seg->p0.x && seg->p1.x < box->max.x && dx < 0.0f) {
        float t = box->max.x - seg->p0.x;
        float y = t * dy / dx + seg->p0.y;
        float z = t * dz / dx + seg->p0.z;
        if (y < box->max.y && box->min.y < y && z < box->max.z && box->min.z < z) {
            v.x = box->max.x; v.y = y; v.z = z; v.w = 1.0f;
            *point = v;
            v.x = 1.0f; v.y = 0.0f; v.z = 0.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    if (seg->p0.x < box->min.x && box->min.x < seg->p1.x && dx > 0.0f) {
        float t = box->min.x - seg->p0.x;
        float y = t * dy / dx + seg->p0.y;
        float z = t * dz / dx + seg->p0.z;
        if (y < box->max.y && box->min.y < y && z < box->max.z && box->min.z < z) {
            v.x = box->min.x; v.y = y; v.z = z; v.w = 1.0f;
            *point = v;
            v.x = -1.0f; v.y = 0.0f; v.z = 0.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    if (box->max.y < seg->p0.y && seg->p1.y < box->max.y && dy < 0.0f) {
        float t = box->max.y - seg->p0.y;
        float x = t * dx / dy + seg->p0.x;
        float z = t * dz / dy + seg->p0.z;
        if (x < box->max.x && box->min.x < x && z < box->max.z && box->min.z < z) {
            v.x = x; v.y = box->max.y; v.z = z; v.w = 1.0f;
            *point = v;
            v.x = 0.0f; v.y = 1.0f; v.z = 0.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    if (seg->p0.y < box->min.y && box->min.y < seg->p1.y && dy > 0.0f) {
        float t = box->min.y - seg->p0.y;
        float x = t * dx / dy + seg->p0.x;
        float z = t * dz / dy + seg->p0.z;
        if (x < box->max.x && box->min.x < x && z < box->max.z && box->min.z < z) {
            v.x = x; v.y = box->min.y; v.z = z; v.w = 1.0f;
            *point = v;
            v.x = 0.0f; v.y = -1.0f; v.z = 0.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    if (box->max.z < seg->p0.z && seg->p1.z < box->max.z && dz < 0.0f) {
        float t = box->max.z - seg->p0.z;
        float x = t * dx / dz + seg->p0.x;
        float y = t * dy / dz + seg->p0.y;
        if (x < box->max.x && box->min.x < x && y < box->max.y && box->min.y < y) {
            v.x = x; v.y = y; v.z = box->max.z; v.w = 1.0f;
            *point = v;
            v.x = 0.0f; v.y = 0.0f; v.z = 1.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    if (seg->p0.z < box->min.z && box->min.z < seg->p1.z && dz > 0.0f) {
        float t = box->min.z - seg->p0.z;
        float x = t * dx / dz + seg->p0.x;
        float y = t * dy / dz + seg->p0.y;
        if (x < box->max.x && box->min.x < x && y < box->max.y && box->min.y < y) {
            v.x = x; v.y = y; v.z = box->min.z; v.w = 1.0f;
            *point = v;
            v.x = 0.0f; v.y = 0.0f; v.z = -1.0f; v.w = 0.0f;
            *normal = v;
            return 1;
        }
    }
    return 0;
}
