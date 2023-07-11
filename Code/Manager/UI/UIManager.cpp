#include "UIManager.h"
#include "Input/Input.h"

#include "FontManager.h"

using namespace Input;

#include <vector>
#include <exception>

//--------------------------------------------------

#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_IMPLEMENTATION

#include <Extensions/nuklear.h>

//nk_context *Getter()
//{
//    static struct nk_context* ctx = NULL;
//    if (!ctx) { ctx = (nk_context*)malloc(sizeof(nk_context)); }
//    return ctx;
//}

struct nk_context ctx;


//--------------------------------------------------

void UIManager::Init()
{
    FontManager::Init();

    const int dxFont = FontManager::GetFontHandle("JFドットM+H10");

	/* フォント初期化 */
	struct nk_user_font nkFont;
	nkFont.userdata = nk_handle_id(dxFont);				// フォントハンドル
	nkFont.height = static_cast<float>(12);		// フォントの高さ

	// フォント幅自動調整
	nkFont.width = [](const nk_handle handle, float h, const char* str, const int len) -> float {
		return static_cast<float>(GetDrawStringWidthToHandle(str, len, handle.id));
	};

    nk_init_default(&ctx, &nkFont);
}

void UIManager::Update()
{
	CheckInput();

    RenderTest();
	GUIRender();

}

void UIManager::OnEnd()
{
    nk_free(&ctx);
}

//--------------------------------------------------

void UIManager::CheckInput()
{
	nk_input_begin(&ctx);	// 判定開始

	// マウス位置を適用
	VECTOR mousePos = Mouse::GetMousePosition();
    int mouseX = (int)mousePos.x;
    int mouseY = (int)mousePos.y;

	nk_input_motion(&ctx, mouseX, mouseY);

	// マウスボタン入力を適用
	nk_input_button(&ctx, NK_BUTTON_LEFT, mouseX, mouseY, Mouse::GetMouseButton(MOUSE_INPUT_LEFT) != 0);
	nk_input_button(&ctx, NK_BUTTON_LEFT, mouseX, mouseY, Mouse::GetMouseButton(MOUSE_INPUT_RIGHT) != 0);
	nk_input_button(&ctx, NK_BUTTON_LEFT, mouseX, mouseY, Mouse::GetMouseButton(MOUSE_INPUT_MIDDLE) != 0);

	// マウススクロール入力を適用
	nk_input_scroll(&ctx, nk_vec2(GetMouseHWheelRotVolF(), GetMouseWheelRotVolF()));

	nk_input_end(&ctx);		// 判定終了
}

// クソ長いので、既存のコードのコピペです。
// < 参照元：https://gitlab.com/-/snippets/1791051 | 紹介ページ：https://qiita.com/ta_dragon/items/b30c190d2108fd915e92#%E6%8F%8F%E7%94%BB%E5%87%A6%E7%90%86 >
void UIManager::GUIRender()
{
    const struct nk_command* cmd = 0;

    nk_foreach(cmd, &ctx)
    {
        switch (cmd->type) {
        case NK_COMMAND_NOP:
            break;

        case NK_COMMAND_SCISSOR: {
            const auto s = reinterpret_cast<const struct nk_command_scissor*>(cmd);
            SetDrawArea(s->x, s->y, s->x + s->w, s->y + s->h);
        } break;

        case NK_COMMAND_LINE: {
            const auto l = reinterpret_cast<const struct nk_command_line*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, l->color.a);
            DrawLine(l->begin.x, l->begin.y, l->end.x, l->end.y, GetColor(l->color.r, l->color.g, l->color.b));
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_RECT: {
            const auto r = reinterpret_cast<const struct nk_command_rect*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, r->color.a);
            DrawBox(r->x, r->y, r->x + r->w, r->y + r->h, GetColor(r->color.r, r->color.g, r->color.b), FALSE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_RECT_FILLED: {
            const auto r = reinterpret_cast<const struct nk_command_rect_filled*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, r->color.a);
            DrawRoundRect(r->x, r->y, r->x + r->w, r->y + r->h, r->rounding, r->rounding, GetColor(r->color.r, r->color.g, r->color.b), TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_CIRCLE: {
            const auto c = reinterpret_cast<const struct nk_command_circle*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, c->color.a);
            DrawOval(c->x + c->w / 2, c->y + c->h / 2, c->w / 2, c->h / 2, GetColor(c->color.r, c->color.g, c->color.b), FALSE, c->line_thickness);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_CIRCLE_FILLED: {
            const auto c = reinterpret_cast<const struct nk_command_circle_filled*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, c->color.a);
            DrawOval(c->x + c->w / 2, c->y + c->h / 2, c->w / 2, c->h / 2, GetColor(c->color.r, c->color.g, c->color.b), TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_TRIANGLE: {
            const auto t = reinterpret_cast<const struct nk_command_triangle*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, t->color.a);
            DrawTriangle(t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y, GetColor(t->color.r, t->color.g, t->color.b), FALSE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_TRIANGLE_FILLED: {
            const auto t = reinterpret_cast<const struct nk_command_triangle_filled*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, t->color.a);
            DrawTriangle(t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y, GetColor(t->color.r, t->color.g, t->color.b), TRUE);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_POLYGON: {
            const auto p = reinterpret_cast<const struct nk_command_polygon*>(cmd);

            std::vector<LINEDATA> line_list;

            if (p->point_count == 0) {
                break;
            }

            const auto first = p->points[0];
            auto start = p->points[0];

            for (int i = 0; i < p->point_count; ++i) {
                LINEDATA l;
                l.x1 = start.x;
                l.y1 = start.y;
                l.x2 = p->points[i].x;
                l.y2 = p->points[i].y;
                l.color = GetColor(p->color.r, p->color.g, p->color.b);;
                l.pal = p->color.a;
                start = p->points[i];
                line_list.push_back(l);
            }

            if ((p->point_count % 2) != 0) {
                LINEDATA l;
                l.x1 = first.x;
                l.y1 = first.y;
                l.x2 = p->points[p->point_count - 1].x;
                l.y2 = p->points[p->point_count - 1].y;
                l.color = GetColor(p->color.r, p->color.g, p->color.b);;
                l.pal = p->color.a;
                line_list.push_back(l);
            }

            DrawLineSet(&line_list[0], line_list.size());
        } break;

        case NK_COMMAND_POLYGON_FILLED: {
            const auto p = reinterpret_cast<const struct nk_command_polygon_filled*>(cmd);
            std::vector<VERTEX2D> point_list;
            for (int i = 0; i < p->point_count; ++i) {
                VERTEX2D ver;
                ver.pos.x = p->points[i].x;
                ver.pos.y = p->points[i].y;
                ver.dif = GetColorU8(p->color.r, p->color.g, p->color.b, p->color.a);
                point_list.push_back(ver);
            }
            DrawPolygon2D(&point_list[0], point_list.size(), DX_NONE_GRAPH, TRUE);
        } break;

        case NK_COMMAND_POLYLINE: {
            const auto p = reinterpret_cast<const struct nk_command_polyline*>(cmd);
            std::vector<LINEDATA> line_list;

            if (p->point_count == 0) {
                break;
            }
            auto start = p->points[0];
            for (int i = 0; i < p->point_count; i += 2) {
                LINEDATA l;
                l.x1 = start.x;
                l.y1 = start.y;
                l.x2 = p->points[i].x;
                l.y2 = p->points[i].y;
                l.color = GetColor(p->color.r, p->color.g, p->color.b);;
                l.pal = p->color.a;
                start = p->points[i];
                line_list.push_back(l);
            }
            DrawLineSet(&line_list[0], line_list.size());
        } break;

        case NK_COMMAND_TEXT: {
            const auto t = reinterpret_cast<const struct nk_command_text*>(cmd);
            const auto font_handle = t->font->userdata.id;
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, t->foreground.a);
            DrawNStringToHandle(t->x, t->y, static_cast<const char*>(t->string), t->length, GetColor(t->foreground.r, t->foreground.g, t->foreground.b), font_handle);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_CURVE: {
            const auto q = reinterpret_cast<const struct nk_command_curve*>(cmd);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, q->color.a);
            DrawLine(q->begin.x, q->begin.y, q->end.x, q->end.y, GetColor(q->color.r, q->color.g, q->color.b), q->line_thickness);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        } break;

        case NK_COMMAND_IMAGE: {
            const auto i = reinterpret_cast<const struct nk_command_image*>(cmd);
            DrawGraph(i->x, i->y, i->img.handle.id, TRUE);
        } break;

        case NK_COMMAND_RECT_MULTI_COLOR:
        case NK_COMMAND_ARC:
        case NK_COMMAND_ARC_FILLED:
        default:
            break;
        }
    }

    nk_clear(&ctx);
}

void UIManager::RenderTest()
{
    // nuklearのレイアウト作成
    enum { EASY, HARD };
    static int op = EASY;
    static float value = 0.6f;

    if (nk_begin(&ctx, "Show", nk_rect(50, 50, 220, 220),
        NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_CLOSABLE)) {
        /* fixed widget pixel width */
        nk_layout_row_static(&ctx, 30, 80, 1);
        if (nk_button_label(&ctx, "button")) {
            /* event handling */
        }

        /* fixed widget window ratio width */
        nk_layout_row_dynamic(&ctx, 30, 2);
        if (nk_option_label(&ctx, "easy", op == EASY)) op = EASY;
        if (nk_option_label(&ctx, "hard", op == HARD)) op = HARD;

        /* custom widget pixel width */
        nk_layout_row_begin(&ctx, NK_STATIC, 30, 2);
        {
            nk_layout_row_push(&ctx, 50);
            nk_label(&ctx, "Volume:", NK_TEXT_LEFT);
            nk_layout_row_push(&ctx, 110);
            nk_slider_float(&ctx, 0, &value, 1.0f, 0.1f);
        }
        nk_layout_row_end(&ctx);
    }
    nk_end(&ctx);
}