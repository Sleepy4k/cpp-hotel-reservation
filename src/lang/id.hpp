#include <map>
#include <string>

using namespace std;

#ifndef LANG_ID_HPP
#define LANG_ID_HPP

/**
 * @brief Indonesian translations
 * 
 * @var map<string, string>
 */
map<string, string> indonesian_translations = {
  {"app_name", "Sistem Reservasi Hotel"},
  
  {"menu_list_main_welcome", "Selamat Datang Di Halaman Utama"},
  {"menu_list_main_admin", "Dasbor Admin"},
  {"menu_list_main_user", "Dasbor Pengguna"},
  {"menu_list_main_register", "Registrasi Pengguna"},
  {"menu_list_main_forgot", "Lupa Kata Sandi"},
  {"menu_list_main_exit", "Keluar"},
  {"menu_list_main_press", "Tekan"},
  {"menu_list_main_invalid", "Menu tidak valid"},
  {"menu_list_main_thanks", "Terima Kasih Telah Menggunakan"},

  {"menu_list_forgot_pet", "Apa nama hewan peliharaan favoritmu?"},
  {"menu_list_forgot_color", "Apa warna favoritmu?"},
  {"menu_list_forgot_food", "Apa makanan favoritmu?"},
  {"menu_list_forgot_person", "Siapa orang favoritmu?"},

  {"validation_integer_input", "Silakan masukkan pilihan anda: "},
  {"validation_integer_invalid", "Silakan masukkan nomor yang valid!!"},
  {"validation_integer_between", "Silakan masukkan angka antara % dan %!!"},

  {"validation_string_invalid", "Silakan masukkan data yang valid!!"},

  {"model_user_created", "dibuat"},
  {"model_user_updated", "diperbarui"},
  {"model_user_deleted", "dihapus"},
  {"model_user_notfound", "Pengguna tidak ditemukan"},
  {"model_user_all_success", "Pengguna berhasil %"},
  {"model_user_already_exist", "Nama pengguna sudah ada"},

  {"register_title", "Daftarkan akun anda"},
  {"register_input_username", "Silakan Masukkan Nama Pengguna Anda: "},
  {"register_input_password", "Silakan Masukkan Kata Sandi Anda: "},
  {"register_input_confirm_password", "Silakan Masukkan Konfirmasi Kata Sandi Anda: "},
  {"register_input_password_not_same", "Kata sandi dan konfirmasi kata sandi harus sama"},

  {"login_title", "Masuk ke Akun Anda"},
  {"login_input_username", "Silakan Masukkan Nama Pengguna Anda: "},
  {"login_input_password", "Silakan Masukkan Kata Sandi Anda: "},
  {"login_not_admin", "Anda bukan admin"},
  {"login_invalid_password", "Kata sandi salah"},

  {"login_confirm_question", "lupa kata sandi Anda? (y/n)"},
  {"login_confirm_input_confirm", "Silakan Masukkan Konfirmasi Anda: "},
  {"login_confirm_input_invalid", "Konfirmasi harus y atau n"},

  {"forgot_title", "Lupa kata sandi Anda"},
  {"forgot_input_username", "Silakan Masukkan Nama Pengguna Anda: "},

  {"forgot_validate_title", "Validasi Pertanyaan Lupa"},
  {"forgot_validate_input_answer", "Tolong masukan jawaban anda: "},
  {"forgot_validate_input_password", "Silakan Masukkan Kata Sandi Baru Anda: "},
  {"forgot_validate_input_confirm_password", "Silakan Masukkan Konfirmasi Kata Sandi Baru Anda: "},
  {"forgot_validate_input_password_invalid", "Jawabannya salah"},
  {"forgot_validate_input_password_not_same", "Kata sandi dan konfirmasi kata sandi harus sama"},
  {"forgot_validate_input_password_must_be_different", "Kata sandi harus berbeda dengan kata sandi lama"},

  {"forgot_create_title", "Buat Pertanyaan Lupa"},
  {"forgot_create_press", "Tekan"},
  {"forgot_create_input_answer", "Tolong masukan jawaban anda: "},
  {"forgot_create_invalid_menu", "Menu tidak valid"},
};

#endif