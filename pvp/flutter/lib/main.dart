import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class Task {
  final String nadpis;
  final String obsah;
  final bool status;
  final int id;

  Task({
    required this.nadpis,
    required this.obsah,
    required this.status,
    required this.id
  });

  factory Task.fromJson(Map<String, dynamic> json) {
    return Task(
      nadpis: json['nadpis'],
      obsah: json['obsah'],
      status: json['status'],
      id: json['_id']
    );
  }

  Task copyWith({
    String? nadpis,
    String? obsah,
    bool? status,
    int? id}) {
    return Task(
      nadpis: nadpis ?? this.nadpis,
      obsah: obsah ?? this.obsah,
      status: status ?? this.status,
      id: id ?? this.id
    );
  }
}

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: TaskList(),
      /*home: const MyHomePage(title: 'Flutter Demo Home Page'),*/
    );
  }
}

// widget pro zobrazovani seznamu ukolu
class TaskList extends StatefulWidget {
  @override
  _TaskListState createState() => _TaskListState();
}

class _TaskListState extends State<TaskList> {
  late Future<List<Task>> futureTasks;

  @override
  void initState() {
    super.initState();
    futureTasks = fetchTasks();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Task List'),
      ),
      body: FutureBuilder<List<Task>>(
        future: futureTasks,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            return ListView.builder(
              itemCount: snapshot.data!.length,
              itemBuilder: (context, index) {
                return ListTile(
                  title: Text(snapshot.data![index].nadpis),
                  subtitle: Text(snapshot.data![index].obsah),
                  trailing: Checkbox(
                    value: snapshot.data![index].status,
                    onChanged: (bool? value) {
                      setState(() {
                        snapshot.data![index].copyWith(status: value);
                      });
                    },
                  ),
                );
              },
            );
          } else if (snapshot.hasError) {
            return Text('${snapshot.error}');
          }
          return const CircularProgressIndicator();
        },
      ),
    );
  }
}

  Future<List<Task>> fetchTasks() async {
    final response = await http.get(Uri.parse('https://poznamky.cokoliv.eu/seznam'));
    if (response.statusCode == 200) {
      List jsonResponse = json.decode(response.body);
      return jsonResponse.map((task) => Task.fromJson(task)).toList();
    } else {
      throw Exception('Failed to load tasks');
    }
  }