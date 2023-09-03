#pragma once

void ImRotateStart();

ImVec2 ImRotationCenter();

ImVec2 operator-(const ImVec2& l, const ImVec2& r);

void ImRotateEnd(float rad, ImVec2 center = ImRotationCenter());
