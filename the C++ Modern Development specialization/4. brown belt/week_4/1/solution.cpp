#include "Common.h"

using namespace std;

class Rectangle: public IShape {
public:
    Rectangle() {}
    Rectangle(shared_ptr<ITexture> it, Size sz_, Point p_):
        texture(it), sz(sz_), p(p_) {}
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Rectangle>(texture, sz, p);
    }

    void SetPosition(Point p_) override {
        p = p_;
    }
    Point GetPosition() const override {
        return p;
    }

    void SetSize(Size s) override {
        sz = s;
    }
    Size GetSize() const override {
        return sz;
    }

    void SetTexture(std::shared_ptr<ITexture> txt) override {
        texture = move(txt);
    }
    ITexture* GetTexture() const override {
        return texture.get();
    }
    // Рисует фигуру на указанном изображении
    void Draw(Image& im) const override {
        for (int i = p.y; i < im.size(); ++i) {
            if (i - p.y < sz.height) {
                for (int j = p.x; j < im[0].size(); ++j) {
                    if (j - p.x < sz.width) {
                        if (texture == nullptr) {
                            im[i][j] = '.';
                        } else {
                            if (i >= p.y && i < p.y + texture->GetSize().height &&
                                j >= p.x && j < p.x + texture->GetSize().width) {
                                    im[i][j] = texture->GetImage()[i - p.y][j - p.x];
                            } else {
                                im[i][j] = '.';
                            }
                        }
                    }
                }
            }
        }
    }
private:
    shared_ptr<ITexture> texture;
    Size sz;
    Point p;
};


class Ellipse: public IShape {
public:
    Ellipse() {}
    Ellipse(shared_ptr<ITexture> it, Size sz_, Point p_):
        texture(it), sz(sz_), p(p_) {}
    std::unique_ptr<IShape> Clone() const override {
        return make_unique<Ellipse>(texture, sz, p);
    }

    void SetPosition(Point p_) override {
        p = p_;
    }
    Point GetPosition() const override {
        return p;
    }

    void SetSize(Size s) override {
        sz = s;
    }
    Size GetSize() const override {
        return sz;
    }

    void SetTexture(std::shared_ptr<ITexture> txt) override {
        texture = move(txt);
    }
    ITexture* GetTexture() const override {
        return texture.get();
    }

    // Рисует фигуру на указанном изображении
    void Draw(Image& im) const override {
        for (int i = p.y; i < im.size(); ++i) {
            if (i - p.y < sz.height) {
                for (int j = p.x; j < im[0].size(); ++j) {
                    if (j - p.x < sz.width) {
                        if (texture == nullptr) {
                            im[i][j] = '.';
                        } else {
                            if (IsPointInEllipse({j - p.x, i - p.y}, sz)) {
                                if (i >= p.y && i < p.y + texture->GetSize().height &&
                                    j >= p.x && j < p.x + texture->GetSize().width) {
                                        im[i][j] = texture->GetImage()[i - p.y][j - p.x];
                                } else {
                                    im[i][j] = '.';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
private:
    shared_ptr<ITexture> texture;
    Size sz;
    Point p;
};

// Напишите реализацию функции
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    if (shape_type == ShapeType::Rectangle) {
        return make_unique<Rectangle>();
    } else if (shape_type == ShapeType::Ellipse) {
        return make_unique<Ellipse>();
    } else {
        return nullptr;
    }
}