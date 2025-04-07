class User {
  final String? jmeno; // username instead of email
  final String? token;

  User({
    this.jmeno,
    this.token,
  });

  factory User.fromJson(Map<String, dynamic> json) {
    return User(
      jmeno: json['message'] != null ? json['jmeno'] : null,
      token: json['token'],
    );
  }
}