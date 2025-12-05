#if !defined VA_PLUGIN_INC
	#define VA_PLUGIN_INC
	#if !defined __cplusplus

		enum e_handling_id
		{
			hd_mass,
			hd_turn_mass,
			hd_drag_coeff,
			hd_center_of_mass_x,
			hd_center_of_mass_y,
			hd_center_of_mass_z,
			hd_traction_multiplier,
			hd_traction_loss,
			hd_traction_bias,
			hd_max_velocity,
			hd_engine_acceleration,
			hd_engine_inertia,
			hd_brake_deceleration,
			hd_brake_bias,
			hd_steering_lock,
			hd_suspension_force_level,
			hd_suspension_damping_level,
			hd_suspension_high_speed,
			hd_suspension_upper_limit,
			hd_suspension_lower_limit,
			hd_suspension_bias_between_fr,
			hd_suspension_anti_div_mult,
			hd_seat_offset_distance,
			hd_collision_damage_mult,
			hd_wheel_scale,
			hd_model_flags,
			hd_handling_flags,
			hd_abs,
			hd_head_light,
			hd_tail_light,
			hd_anim_group,
			hd_drive_type,
			hd_engine_type,
			hd_percent_submerged,
			hd_number_of_gears
		};

		// Get the value of the specified vehicle
		native GetVehicleHandlingInt(vehicleid, e_handling_id:param_id, &value);
		native GetVehicleHandlingFloat(vehicleid, e_handling_id:param_id, &Float:value);

		// Set the value for the specified vehicle
		native SetVehicleHandlingInt(vehicleid, e_handling_id:param_id, value);
		native SetVehicleHandlingFloat(vehicleid, e_handling_id:param_id, Float:value);
		
		// Apply changes for the specified vehicle
		native ApplyVehicleHandlingChanges(vehicleid);

	#endif
#endif