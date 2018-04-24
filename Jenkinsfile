pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'mkdir build && cd build && cmake .. && make'
      }
    }
    stage('Test') {
      steps {
        sh 'cd build && tests/testfoo --gtest_output="xml:testresults.xml"'
      }
    }
  }
}