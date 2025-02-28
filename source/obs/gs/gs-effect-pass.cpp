// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2017-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// Copyright (C) 2022 lainon <GermanAizek@yandex.ru>
// AUTOGENERATED COPYRIGHT HEADER END

#include "gs-effect-pass.hpp"

#include "warning-disable.hpp"
#include <cstring>
#include "warning-enable.hpp"

extern "C" {
#include "warning-disable.hpp"
#include <graphics/effect.h>
#include "warning-enable.hpp"
}

streamfx::obs::gs::effect_pass::effect_pass(gs_epass_t* pass, std::shared_ptr<gs_technique_t> parent) : _parent(parent)
{
	reset(pass, [](void*) {});
}

streamfx::obs::gs::effect_pass::~effect_pass() = default;

std::string streamfx::obs::gs::effect_pass::name()
{
	const char* name_c   = get()->name;
	std::size_t name_len = strnlen(name_c, 256);
	return name_c ? std::string(name_c, name_c + name_len) : std::string();
}

std::size_t streamfx::obs::gs::effect_pass::count_vertex_parameters()
{
	return static_cast<size_t>(get()->vertshader_params.num);
}

streamfx::obs::gs::effect_parameter streamfx::obs::gs::effect_pass::get_vertex_parameter(std::size_t idx)
{
	if (idx >= count_vertex_parameters())
		return nullptr;

	return streamfx::obs::gs::effect_parameter((get()->vertshader_params.array + idx)->eparam, *this);
}

streamfx::obs::gs::effect_parameter streamfx::obs::gs::effect_pass::get_vertex_parameter(std::string_view name)
{
	for (std::size_t idx = 0; idx < count_vertex_parameters(); idx++) {
		auto ptr = get()->vertshader_params.array + idx;
		if (strcmp(ptr->eparam->name, name.data()) == 0)
			return streamfx::obs::gs::effect_parameter(ptr->eparam, *this);
	}
	return nullptr;
}

bool streamfx::obs::gs::effect_pass::has_vertex_parameter(std::string_view name)
{
	return (get_vertex_parameter(name) != nullptr);
}

bool streamfx::obs::gs::effect_pass::has_vertex_parameter(std::string_view name, streamfx::obs::gs::effect_parameter::type type)
{
	if (auto el = get_vertex_parameter(name); el != nullptr) {
		return el.get_type() == type;
	}
	return false;
}

std::size_t streamfx::obs::gs::effect_pass::count_pixel_parameters()
{
	return static_cast<size_t>(get()->pixelshader_params.num);
}

streamfx::obs::gs::effect_parameter streamfx::obs::gs::effect_pass::get_pixel_parameter(std::size_t idx)
{
	if (idx >= count_pixel_parameters())
		return nullptr;

	return streamfx::obs::gs::effect_parameter((get()->pixelshader_params.array + idx)->eparam, *this);
}

streamfx::obs::gs::effect_parameter streamfx::obs::gs::effect_pass::get_pixel_parameter(std::string_view name)
{
	for (std::size_t idx = 0; idx < count_pixel_parameters(); idx++) {
		auto ptr = get()->pixelshader_params.array + idx;
		if (strcmp(ptr->eparam->name, name.data()) == 0)
			return streamfx::obs::gs::effect_parameter(ptr->eparam, *this);
	}
	return nullptr;
}

bool streamfx::obs::gs::effect_pass::has_pixel_parameter(std::string_view name)
{
	return (get_pixel_parameter(name) != nullptr);
}

bool streamfx::obs::gs::effect_pass::has_pixel_parameter(std::string_view name, streamfx::obs::gs::effect_parameter::type type)
{
	if (auto el = get_pixel_parameter(name); el != nullptr) {
		return el.get_type() == type;
	}
	return false;
}
