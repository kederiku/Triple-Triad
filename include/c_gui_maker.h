#ifndef __LIB2D_C_GUI_MAKER__
#define __LIB2D_C_GUI_MAKER__

#include "c_buffer.h"
#include "items_classes.h"

namespace	Lib2D
{
	enum	e_param_type
	{
		E_INTEGER,
		E_BOOLEAN,
		E_STRING
	};
	class	c_param
	{
		private:
			e_param_type	__v_param_type;
		public:
					c_param(e_param_type param_type);
					c_param(const c_param& right);
			virtual		~c_param(void);
			c_param&	operator=(const c_param& right);
			e_param_type	f_type(void) const;
	};
	class	c_param_int: public c_param
	{
		private:
			int	__v_val;
		public:
					c_param_int(int val);
					c_param_int(const c_param_int& right);
			virtual		~c_param_int(void);
			c_param_int&	operator=(const c_param_int& right);
			int		f_val(void) const;
			void		f_val(int val);
	};
	class	c_param_bool: public c_param
	{
		private:
			bool	__v_val;
		public:
					c_param_bool(bool val);
					c_param_bool(const c_param_bool& right);
			virtual		~c_param_bool(void);
			c_param_bool&	operator=(const c_param_bool& right);
			bool		f_val(void) const;
			void		f_val(bool val);
	};
	class	c_param_str: public c_param
	{
		private:
			const char*	__v_val;
		private:
			void	__f_destroy(void);
		public:
					c_param_str(const char* val);
					c_param_str(const c_param_str& right);
			virtual		~c_param_str(void);
			c_param_str&	operator=(const c_param_str& right);
			const char*	f_val(void) const;
			void		f_val(const char* val);
	};
	class	c_gui_maker
	{
		public:
			enum	e_item_type
			{
				E_CONTEXT,
				E_IMAGE,
				E_DAREA,
				E_LABEL,
				E_LABEL_LINK,
				E_BUTTON,
				E_BUTTON_LABEL,
				E_BUTTON_TOGGLE,
				E_BUTTON_CHECK,
				E_BUTTON_PICTURE,
				E_TEXTBOX,
				E_TEXTBOX_NUM,
				E_TEXTBOX_ALPHA,
				E_POPUP,
				E_HBOX,
				E_VBOX
			};
			typedef std::vector<c_param*>		t_param_vector;
			typedef std::vector<c_param*>::iterator	t_param_it;
			struct	s_item
			{
				Lib2D::Control*	item;
				t_param_vector	item_params;
				e_item_type	item_type;
				size_t		item_depth;
			};
			typedef std::list<s_item*>		t_item_list;
			typedef std::list<s_item*>::iterator	t_item_it;
		private:
			ns_cmc::c_buffer	__v_buf;
			t_item_list		__v_items;
		private:
			bool		__f_get_conf(const char* contexts_file,
						     const char* root_path);
			bool		__f_items_factoring(void);
			bool		__f_create_item(const char* line);
			void		__f_print_newly_created(const s_item* item) const;
			c_param*	__f_create_parameter(const char* param) const;
			Lib2D::Control*	__f_create_control(const char* item_type, s_item* item);
			bool		__f_items_initialization(void);
			bool		__f_place_and_size(s_item* item);
			bool		__f_item_spec_init(s_item* item);
			bool		__f_context_init(Lib2D::Context* context,
							 std::vector<c_param*>& params);
			bool		__f_image_init(Lib2D::Image* image,
						       std::vector<c_param*>& params);
			bool		__f_darea_init(Lib2D::Darea* darea,
						       std::vector<c_param*>& params);
			bool		__f_label_init(Lib2D::Label* label,
						       std::vector<c_param*>& params);
			bool		__f_label_link_init(Lib2D::Label_link* label_link,
							    std::vector<c_param*>& params);
			bool		__f_button_init(Lib2D::Button* button,
							std::vector<c_param*>& params);
			bool		__f_button_check_init(Lib2D::Button_check* button_check,
							std::vector<c_param*>& params);
			template <typename T>
			bool		__f_textbox_init(T* textbox,
							 std::vector<c_param*>& params);
			bool		__f_box_init(Lib2D::Box* box,
						     std::vector<c_param*>& params);
			void		__f_item_hierarchy(t_item_it& item);
		public:
					c_gui_maker(void);
					c_gui_maker(const c_gui_maker& right);
					~c_gui_maker(void);
			c_gui_maker&	operator=(const c_gui_maker& right);
			bool		f_create_gui(const char* conf_file,
						     const char* root_path = "");
	};
}

#endif
