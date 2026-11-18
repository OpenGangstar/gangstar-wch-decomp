#ifndef WCH_RENDERING_FLASH_MATRIX_H
#define WCH_RENDERING_FLASH_MATRIX_H

namespace gameswf {
struct point {
    point(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x, y;
};
class matrix {
public:
    matrix();
    void concatenate_translation(float x, float y);
    float get_x_scale() const;
    float get_y_scale() const;
    float get_rotation() const;
    void set_scale_rotation(float xScale, float yScale, float rotation);
    void transform(point* output, const point& input) const;
    void set_inverse(const matrix& original);

private:
    float elements[6];
};
}

#endif
