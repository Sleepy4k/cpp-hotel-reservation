#pragma once

#ifndef LANG_ID_HPP
#define LANG_ID_HPP

#include <map>

using std::map;
using std::string;

/**
 * @brief Indonesian translations
 * 
 * @var map<string, string>
 */
const map<string, string> indonesian_translations = {
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

  {"menu_list_admin_title", "Selamat datang, % ke admin dasbor"},
  {"menu_list_admin_manage_room", "Kelola Kamar"},
  {"menu_list_admin_manage_user", "Kelola Pengguna"},
  {"menu_list_admin_manage_booking", "Kelola Pemesanan"},
  {"menu_list_admin_manage_admin", "Kelola Admin"},
  {"menu_list_admin_manage_system", "Kelola Sistem"},
  {"menu_list_admin_report_and_statistic", "Laporan dan Statistik"},
  {"menu_list_admin_press", "Tekan"},
  {"menu_list_admin_logout", "Keluar"},
  {"menu_list_admin_invalid", "Menu tidak valid"},

  {"menu_list_user_title", "Selamat datang, % ke pengguna dasbor"},
  {"menu_list_user_search_room", "Ruang Pencarian"},
  {"menu_list_user_booking_room", "Ruang Pemesanan"},
  {"menu_list_user_booking_history", "Sejarah Pemesanan"},
  {"menu_list_user_profile", "Profil"},
  {"menu_list_user_press", "Tekan"},
  {"menu_list_user_logout", "Keluar"},
  {"menu_list_user_invalid", "Menu tidak valid"},

  {"menu_list_admin_system_title", "Hai %, selamat datang di dasbor admin sistem"},
  {"menu_list_admin_system_language", "Kelola Bahasa"},
  {"menu_list_admin_system_debug", "Kelola Debug"},
  {"menu_list_admin_system_back", "Kembali"},
  {"menu_list_admin_system_press", "Tekan"},
  {"menu_list_admin_system_invalid", "Menu tidak valid"},

  {"menu_list_admin_room_title", "Hai %, selamat datang di dasbor admin ruangan"},
  {"menu_list_admin_room_list", "Tampilkan Semua Ruangan"},
  {"menu_list_admin_room_add", "Tambahkan Ruangan"},
  {"menu_list_admin_room_search", "Ruang Pencarian"},
  {"menu_list_admin_room_edit", "Ubah Ruangan"},
  {"menu_list_admin_room_delete", "Hapus Kamar"},
  {"menu_list_admin_room_back", "Kembali"},
  {"menu_list_admin_room_press", "Tekan"},
  {"menu_list_admin_room_invalid", "Menu tidak valid"},

  {"menu_list_user_profile_title", "Hai %, selamat datang di dasbor user profil"},
  {"menu_list_user_profile_forgot", "Ubah Kata Sandi"},
  {"menu_list_user_profile_back", "Kembali"},
  {"menu_list_user_profile_press", "Tekan"},
  {"menu_list_user_profile_invalid", "Menu tidak valid"},

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

  {"model_room_created", "dibuat"},
  {"model_room_updated", "diperbarui"},
  {"model_room_deleted", "dihapus"},
  {"model_room_notfound", "Kamar tidak ditemukan"},
  {"model_room_all_success", "Kamar berhasil %"},
  {"model_room_already_exist", "Kamar sudah ada"},

  {"model_booking_created", "dibuat"},
  {"model_booking_updated", "diperbarui"},
  {"model_booking_deleted", "dihapus"},
  {"model_booking_notfound", "Pesanan tidak ditemukan"},
  {"model_booking_all_success", "Pesanan berhasil %"},
  {"model_booking_already_exist", "Pesanan sudah ada"},

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

  {"login_confirm_question", "lupa kata sandi Anda? (y/t)"},
  {"login_confirm_input_confirm", "Silakan Masukkan Konfirmasi Anda: "},
  {"login_confirm_input_invalid", "Konfirmasi harus y atau t"},

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

  {"admin_system_input_language", "Silakan masukkan kode bahasa (en, id): "},
  {"admin_system_invalid_language", "bahasa harus en atau id"},
  {"admin_system_input_debug", "Silakan masuk ke mode debug (ya, tidak): "},
  {"admin_system_invalid_debug", "debug harus ya atau tidak"},

  {"admin_room_list_title", "Daftar seluruh ruangan"},
  {"admin_room_list_header", "Ditemukan % total data"},
  {"admin_room_list_data_uid", "UUID : %"},
  {"admin_room_list_data_name", "Nama : %"},
  {"admin_room_list_data_type", "Tipe : %"},
  {"admin_room_list_data_price", "Harga : %"},
  {"admin_room_list_data_capacity", "Kapasitas : %"},
  {"admin_room_list_data_status", "Status : %"},
  {"admin_room_list_empty", "Tidak ada data ditemukan"},

  {"admin_room_add_title", "Buat ruangan baru"},
  {"admin_room_input_name", "Silakan Masukkan Nama Kamar: "},
  {"admin_room_input_type", "Silakan Masukkan Jenis Kamar: "},
  {"admin_room_input_price", "Silakan Masukkan Harga Kamar: "},
  {"admin_room_input_capacity", "Silakan Masukkan Kapasitas Ruangan: "},
  {"admin_room_input_status", "Silakan Masukkan Status Kamar (tersedia/dipesan): "},

  {"admin_room_search_title", "Cari sebuah ruangan"},
  {"admin_room_input_uid", "Silakan Masuk ke UID Kamar: "},
  {"admin_room_search_not_found", "Maaf kamar dengan uid % tidak ditemukan di database kami"},

  {"admin_room_edit_title", "Edit room data"},
  {"admin_room_edit_not_found", "Maaf kamar dengan uid % tidak ditemukan di database kami"},

  {"admin_room_delete_title", "Hapus data kamar"},
};

#endif // LANG_ID_HPP