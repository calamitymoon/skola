import 'package:flutter/material.dart';
import 'screens/devices_screen.dart';
import 'screens/login_screen.dart';
import 'screens/alarm_screen.dart';
import 'screens/agregace_screen.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Měřicí přístroje',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: DefaultTabController(
        length: 3,
        child: Scaffold(
          appBar: AppBar(
            title: Text('Měřicí přístroje'),
            bottom: TabBar(
              tabs: [
                Tab(icon: Icon(Icons.list), text: 'Přístroje'),
                Tab(icon: Icon(Icons.alarm), text: 'Alarmy'),
                Tab(icon: Icon(Icons.analytics), text: 'Agregace'),
              ],
            ),
          ),
          body: TabBarView(
            children: [
              DevicesScreen(),
              LoginScreen(), // replaced by Alarm functionality later
              AgregaceScreen(),
            ],
          ),
        ),
      ),
    );
  }
}