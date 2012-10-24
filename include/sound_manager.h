#ifndef __SONG_MANAGER_H__
#define __SONG_MANAGER_H__

#include <map>
#include <SDL/SDL.h>
#include "singleton.hpp"

enum	e_mode
{
	MODE_REPEAT = 0,
	MODE_NO_REPEAT,
	MODE_STOP
};

enum	e_exist
{
	EXIST,
	NOT_EXIST
};

enum	e_dist
{
	DIST_2D,
	DIST_3D
};

enum	e_type_alloc
{
	NOT_ALLOCED = 0,
	BY_NEW,
	BY_SDL_LOAD_WAV
};

struct	s_sound
{
	SDL_AudioCVT		convert_audio;
	SDL_AudioSpec		sound_file;
	Uint8*			sound_data;
	Uint32			sound_lenght;
	e_type_alloc		type_alloc;
	bool			convert;
};

struct	s_sound_playing
{
	Uint32		pos;
	e_mode		mode;
	struct s_sound*	sound;
	bool		pause;
	int		volume;
	int		left;
	int		right;
};

struct	s_data_spatial
{
	int	space[4][2];
	float	alpha;
	float	beta;
};

void	callback_mix_audio(void* user_data, Uint8* stream, int len);

class	c_sound_manager : public singleton<c_sound_manager>
{
		friend class	singleton<c_sound_manager>;
	public:
		int	init_audio_device(int sound_frequency = 22050, Uint16 format = AUDIO_U8, Uint8 nb_channels = 2, Uint32 size_buffer_sound = 512);
		void	init_data_spatial(int right_left = 30, int right_righ = 100, int top_left = 100, int top_right = 100,
					  int left_left = 100, int left_right = 30, int bot_left = 80, int bot_right = 80,
					  float alpha = 50.0, float beta = 40.0);


//	pour la fonction add_sound() mettez -1 pour la key_stock si vous ne voullez pas la choisir
//	elle seras set automatiquement a la key_stock max + 1
//	et add_sound return la key_stock choisir par vous ou automatiquement
//	cette fonction renvoie -1 en cas d'erreur, vous devrez vraiment checker la valeur -1



		int	add_sound(const char* name, int key_stock = -1);
		void	delete_sound(int key_stock);

//	pour les fonctions de lecture "listen_to_*" mettez -1 pour la key_play si vous ne voullez pas la choisir
//	elle seras set automatiquement a la key_play max + 1
//	et ces trois fonctions return la key_play choisi par vous en argument ou automatiquement
//	ces fonctions renvoies -1 en cas d'erreur, vous devrez vraiment checker la valeur -1


		int	listen_to_sound(int key_stock, int key_play = -1, e_mode mode = MODE_NO_REPEAT,
					int volume_percent = 100, int left_percent = 100, int right_percent = 100);
		int	listen_to_sound_positional(int key_stock, int src_x, int src_y, int src_z, int range_sound,
								  int pos_x, int pos_y, int pos_z, float direction = 0.0,
								  int volume = 100, int key_play = -1, e_mode mode = MODE_NO_REPEAT);
// probleme sur la rotation src(x, y)

		void	stop_all_sound(void);
		void	pause_all_listening(void);
		void	continue_all_listening(void);

		void	stop_one_sound(int key_play);
		void	pause_one_sound_listening(int key_play);
		void	continue_one_sound_listening(int key_play);

		void	set_percent_volume_global(float volume_percent);
		int	get_percent_volume_global(void);
		void	set_percent_balance_global(float left, float right);
		int	get_percent_balance_global(int side); //side: 0 = left, 1 = right

		void	set_percent_volume_track_playing(int key_play, int volume);
		int	get_percent_volume_track_playing(int key_play);
		void	set_percent_balance_track_playing(int key_play, int left, int right);
		int	get_percent_balance_track_playing(int key_play, int side); //side: 0 = left, 1 = right

		void	set_balance_with_position(int key_play,
						  float src_x, float src_y, float src_z, float range_sound,
						  float pos_x, float pos_y, float pos_z, float direction = 0.0);

		int	mutex_lock(void);
		int	mutex_unlock(void);

		std::map<int, struct s_sound_playing*>*	get_m_sound_playing(void);

	private:
		std::map<int, struct s_sound*>		__m_sound_added;
		std::map<int, struct s_sound_playing*>	__m_sound_playing;
		SDL_AudioSpec				__desired;
		SDL_AudioSpec				__obtained;
		pthread_mutex_t				__mutex;
		float					__volume_global;
		float					__left_global;
		float					__right_global;
		struct s_data_spatial			__data_spatial;

		void					__clear_all_sound(void);
		void					__clear_all_sound_playing(void);
		int					__convert_sound(struct s_sound* sound);
		void					__print_format(Uint16 format);
		void					__set_source_sound(float direction, float pos_x, float pos_y, float* src_x, float* src_y);
		e_exist					__check_key_stock(int key_stock);
		e_exist					__check_key_play(int key_play);
		int					__find_auto_key_stock(void);
		int					__find_auto_key_play(void);

	private:
			c_sound_manager(void);
			~c_sound_manager(void);

};

#endif
