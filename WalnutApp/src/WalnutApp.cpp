#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "imgui_internal.h"
#include "imgui_rotate.h"

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		//ImGui::Button("Button");

		ImGui::Text("Hi!");
		ImGui::Dummy(ImVec2(0.0f, 500.0f)); // Down Space (Enter)
		ImGui::Indent(700.0f); // Right Space (Space/Tab)
		//ImGui::SameLine(0.0f, 500.0f);
		ImRotateStart();
		ImGui::Text("--------------------------------X");
		ImRotateEnd(30.0f, ImRotationCenter()); // Edit the degree from 0 - 180 range.
		ImGui::End();

		//ImGui::ShowDemoWindow();
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}