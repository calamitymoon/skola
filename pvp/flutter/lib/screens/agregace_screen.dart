import 'package:flutter/material.dart';
import '../services/api_service.dart';
import '../models/agregace.dart';

class AgregaceScreen extends StatefulWidget {
  @override
  _AgregaceScreenState createState() => _AgregaceScreenState();
}

class _AgregaceScreenState extends State<AgregaceScreen> {
  final ApiService _apiService = ApiService();
  String _selectedPeriod = 'den';
  late Future<AgregaceData> _agregaceData;

  @override
  void initState() {
    super.initState();
    _loadAgregaceData();
  }

  void _loadAgregaceData() {
    setState(() {
      _agregaceData = _apiService.fetchAggregationForPeriod(_selectedPeriod);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Agregované údaje'),
      ),
      body: Column(
        children: [
          DropdownButton<String>(
            value: _selectedPeriod,
            items: ['den', 'tyden', 'mesic', 'rok']
                .map((period) => DropdownMenuItem(
              value: period,
              child: Text(period.toUpperCase()),
            ))
                .toList(),
            onChanged: (value) {
              if (value != null) {
                setState(() {
                  _selectedPeriod = value;
                  _loadAgregaceData();
                });
              }
            },
          ),
          FutureBuilder<AgregaceData>(
            future: _agregaceData,
            builder: (context, snapshot) {
              if (snapshot.connectionState == ConnectionState.waiting) {
                return CircularProgressIndicator();
              } else if (snapshot.hasError) {
                return Text('Chyba: ${snapshot.error}');
              } else if (!snapshot.hasData) {
                return Text('Žádná data');
              }

              final data = snapshot.data!;
              return Column(
                children: [
                  Text('Průměrná teplota: ${data.prumernaTeplota.toStringAsFixed(2)}'),
                  Text('Průměrná vlhkost: ${data.prumernaVlhkost.toStringAsFixed(2)}'),
                  Text('Průměrné CO2: ${data.prumerneCo2.toStringAsFixed(2)}'),
                  Text('Průměrný tlak: ${data.prumernyTlak.toStringAsFixed(2)}'),
                ],
              );
            },
          ),
        ],
      ),
    );
  }
}