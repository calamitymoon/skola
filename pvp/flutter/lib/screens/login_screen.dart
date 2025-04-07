import 'package:flutter/material.dart';
import '../services/api_service.dart';
import '../models/user.dart';
import 'alarm_screen.dart';

class LoginScreen extends StatefulWidget {
  @override
  _LoginScreenState createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  final TextEditingController _jmenoController = TextEditingController();
  final TextEditingController _hesloController = TextEditingController();
  final ApiService _apiService = ApiService();

  void _login() async {
    try {
      final user = await _apiService.loginUser(
          _jmenoController.text,
          _hesloController.text
      );
      ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Přihlášení úspěšné pro ${user.jmeno ?? "uživatel"}'))
      );
      // Navigate to main screen or update state to show admin buttons
      Navigator.pushReplacement(context, MaterialPageRoute(
          builder: (context) => AlarmScreen(userToken: user.token)
      ));
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Přihlášení selhalo: $e'))
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Přihlášení')),
      body: Padding(
        padding: EdgeInsets.all(16.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            TextField(
              controller: _jmenoController,
              decoration: InputDecoration(labelText: 'Jméno'),
            ),
            TextField(
              controller: _hesloController,
              decoration: InputDecoration(labelText: 'Heslo'),
              obscureText: true,
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _login,
              child: Text('Přihlásit se'),
            ),
          ],
        ),
      ),
    );
  }
}