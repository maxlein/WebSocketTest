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
        sh "echo 'pwd: $pwd' > result"
        def output=readFile('result').trim()
        echo "output=$output"
        echo 'ls: $(ls)'
        sh ' cd build && tests/testfoo --gtest_output="xml:testresults.xml" && mkdir reports && mv testresults.xml reports/ '
        echo 'ls: $(ls)'
      }
    }
    stage('Artifact') {
      steps {
        echo 'current folder: $pwd'
        archiveArtifacts(onlyIfSuccessful: true, artifacts: 'build/bin/*, bin/*')
      }
    }
  }
  post {
    always {
      junit 'build/reports/*.xml'

    }

  }
  options {
    timeout(time: 1, unit: 'HOURS')
  }
}